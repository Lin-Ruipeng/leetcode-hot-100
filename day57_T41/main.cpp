#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // 位置交换
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 寻找中断位置
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 != nums[i])
            {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

auto main() -> int
{
    Solution sol;
    vector<int> nums = {-1, 4, 2, 1, 9, 10};

    cout << "result = " << sol.firstMissingPositive(nums) << endl;
}
