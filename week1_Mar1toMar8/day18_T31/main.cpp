#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        for (int i = nums.size() - 1; i > 0; i--)
        {
            // 找到升序就需要处理
            if (nums[i] > nums[i - 1])
            {
                int j = nums.size() - 1;
                for (; j > i - 1; j--) // 这里可以二分优化
                {
                    if (nums[j] > nums[i - 1])
                    {
                        break;
                    }
                }
                swap(nums[i - 1], nums[j]);
                reverse(nums.begin() + i, nums.end());

                return;
            }
        }

        // 肯定是最大了,要排序成最小
        sort(nums.begin(), nums.end());
    }
};

auto main() -> int
{
    vector<int> nums{1, 2, 3, 4, 5, 4, 3};

    Solution sol;
    cout << "原始: ";
    for (const auto &num : nums)
        cout << num << ",";
    cout << endl
         << "修改: ";
    sol.nextPermutation(nums);
    for (const auto &num : nums)
        cout
            << num << ",";
    cout << endl;
}
