#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        // 1. 先排序
        sort(nums.begin(), nums.end());
        // 2. 遍历固定第一个数字

        for (int i = 0; i + 2 < nums.size(); i++)
        {
            // 如果和上次一样,那么就要跳过,防止重复
            if (i && nums[i - 1] == nums[i])
            {
                continue;
            }

            // 3. 双指针搜索
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {

                // 双指针逻辑
                int sum = nums[left] + nums[right];
                if (sum > target)
                {
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    // cout << " i, left, right :" << i << left << right << endl;
                    // 4. 出现答案,记录下并且继续搜索
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;

                    // 这里进行去重,只需要确保左指针指向的值变化了就行
                    while (left < nums.size() && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};

auto main() -> int
{
    // vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<int> nums{0, 0, 0, 0};

    Solution sol;

    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto &row : result)
    {
        cout << "[ ";
        for (const auto &index : row)
        {
            cout << index << ",";
        }
        cout << " ]" << endl;
    }
}