#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 1. 先检查有无元素,获得一个大概区间
        // 2. 再在小区间内，两次查找，找到左右边界
        vector<int> result{-1, -1};

        int left = 0;
        int right = nums.size() - 1;
        // 记录上次位置,供后续使用
        int last_left;
        int last_right;

        if (right == -1)
        {
            return {-1, -1};
        }

        if (nums[left] == target)
        {
            if (nums[right] == target)
            {
                return {left, right};
            }

            // 只需要找右侧边界
            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (nums[middle] == target)
                {
                    left = middle;
                }
                else
                {
                    right = middle;
                }
            }
            return {0, left};
        }
        else if (nums[right] == target)
        {
            if (nums[left] == target)
            {
                return {left, right};
            }

            // 只需要找左侧边界
            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (nums[middle] == target)
                {
                    right = middle;
                }
                else
                {
                    left = middle;
                }
            }
            return {right, (int)nums.size() - 1};
        }
        // 如果目标值不是在最左或者最右的情况,先考虑是不是直接范围外
        else if (target < nums[left] || target > nums[right])
        {
            return {-1, -1};
        }
        else // 若在范围内的处理
        {

            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (nums[middle] == target)
                {
                    // 此时已经找到了,保留原有的边界,继续查找
                    last_left = left;
                    last_right = right;
                    break;
                }
                else if (nums[middle] < target)
                {
                    left = middle;
                }
                else
                {
                    right = middle;
                }
            }

            // 确认是有元素的才行
            if (nums[(left + right) / 2] != target)
            {
                return result;
            }

            // 在小区间内搜索准确边界
            // 先搜左边界
            right = (last_left + last_right) / 2;
            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (nums[middle] == target)
                {
                    right = middle;
                }
                else
                {
                    // 此时  nums[middle] < target
                    // 不存在 nums[middle] > target
                    left = middle;
                }
            }
            result[0] = right; // 记录左侧边界
            // 再搜右边界
            right = last_right;
            left = (last_left + last_right) / 2;
            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (nums[middle] == target)
                {
                    left = middle;
                }
                else
                {
                    // 此时  nums[middle] > target
                    // 不存在 nums[middle] < target
                    right = middle;
                }
            }
            result[1] = left;
        }

        return result;
    };
};

auto main() -> int
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 7;

    // vector<int> nums{5, 5, 5, 5, 5, 5};
    // int target = 5;

    Solution sol;

    cout << "result = " << endl;
    cout << "[";
    for (const auto &num : sol.searchRange(nums, target))
    {
        cout << num << ",";
    }
    cout << "]" << endl;
}