#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 1. 先查找交换位置
        int left = 0;
        int right = nums.size() - 1;
        // 如果 nums[left] < nums[right]说明没有翻转或者说翻转位置为0
        if (nums[left] > nums[right])
        {
            // 当left + 1 == right时说明找到了交界点
            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (nums[middle] > nums[left])
                {
                    left = middle;
                }
                else
                {
                    // 此时必定 nums[middle] < nums[right]
                    right = middle;
                }
            }
        }
        else
        {
            right = 0;
        }
        // 此时 nums[left] 是最大值, nums[right]是最小值

        // 2. 查找目标 先定区间 然后查找
        if (nums[right] <= target && target <= nums[nums.size() - 1])
        {
            // 在右侧区间查找
            left = right;
            right = nums.size() - 1;
        }
        else if (nums[0] <= target && target <= nums[left])
        {
            // 在左侧区间查找
            right = left;
            left = 0;
        }
        else
        {
            // 都不在最大最小范围内 肯定搜不到
            return -1;
        }

        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return -1;
    }
};

auto main() -> int
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2, 3};
    int target = 7;

    Solution sol;
    cout << "result: " << sol.search(nums, target) << endl;
}
