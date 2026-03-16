#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> mp;
        vector<int> result;

        // 1. 建表存最后位置
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]] = i;
        }

        // 2. 一段一段找区间
        int left = 0, right = mp[s[0]]; // 单次寻找的左右区间
        int next_range = mp[s[0]];      // 下次寻找的右区间

        while (left < s.size())
        {
            if (mp[s[left]] == left)
            {
                result.push_back(1);
                left++;
                right = mp[s[left]];
                continue;
            }

            int old_left = left;
            while (left <= right)
            {
                for (int i = left; i < right; i++)
                {
                    if (mp[s[i]] > next_range)
                    {
                        next_range = mp[s[i]];
                    }
                }
                left = right + 1;
                right = next_range;
            }

            result.push_back(right - old_left + 1);
            right = mp[s[left]];
        }
        result.pop_back();
        result.push_back(s.size() - accumulate(result.begin(), result.end(), 0));
        return result;
    }
};

auto main() -> int
{
    Solution sol;
    // string s = "ababcbacadefegdehijhklij";
    string s = "eccbbbbdec";
    // string s = "dccccbaabe";
    // string s = "vhaagbqkaq";

    cout << "result : " << endl;
    cout << "[ ";
    for (const auto &nums : sol.partitionLabels(s))
    {
        cout << "(" << nums << ")" << ',';
    }
    cout << " ]" << endl;
}
