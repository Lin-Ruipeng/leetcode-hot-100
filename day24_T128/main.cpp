#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int maxLength = 0;
        unordered_set<int> set;
        for (const auto &num : nums)
        {
            set.insert(num);
        }
        for (const auto &num : set)
        {
            if (set.count(num - 1))
            {
                // 如果num-1存在就不是开头直接退出
                continue;
            }
            else
            {
                // 如果num-1不存在，就是开头，统计长度！
                int count = 0;
                int temp_num = num;
                while (set.count(temp_num++))
                {
                    count++;
                }
                if (count > maxLength)
                {
                    maxLength = count;
                }
            }
        }
        return maxLength;
    }
};

auto main() -> int
{
    Solution sol;
    vector<int> nums{1, 2, 3, 4, 5, 9};

    cout << "result = " << sol.longestConsecutive(nums) << endl;
}