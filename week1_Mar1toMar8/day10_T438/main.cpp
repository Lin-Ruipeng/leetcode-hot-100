#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;

        if (s.size() < p.size())
            return result;

        string temp(p.size(), '\0');

        // sort(p.begin(), p.end());
        unordered_map<char, int> p_map;
        for (char c : p)
            p_map[c]++;

        for (int i = 0; i <= s.size() - p.size(); i++)
        {
            // 先拷贝
            temp = s.substr(i, p.size());
            // 排序后对比
            // sort(temp.begin(), temp.end());
            // if (temp == p)
            // result.push_back(i);
            auto p_map_temp = p_map;
            bool flag = true;
            for (char c : temp)
            {
                if (--p_map_temp[c] < 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

auto main() -> int
{
    string s = "cbaebabacd", p = "abc";

    Solution sol;

    cout << "[";
    for (auto i : sol.findAnagrams(s, p))
    {
        cout << i << ",";
    }
    cout << "]" << endl;
}
