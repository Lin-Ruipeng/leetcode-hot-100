#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 1;
        int left = 0;
        int right = 0;
        int max_range = 0; // 局部最优选择步的可达范围
        int max_index = 0; // 局部最优选择步的下标

        if (nums.size() == 1)
        {
            return 0;
        }

        // 先检查一步能不能结束
        if (nums[0] >= nums.size() - 1)
        {
            return 1;
        }

        do
        {
            int i = left;
            for (; i <= right; i++)
            {
                int range = i + nums[i];
                if (range >= max_range)
                {
                    max_range = range;
                    max_index = i;
                    if (max_range + 1 >= nums.size())
                    {
                        return step;
                    }
                }
            }
            step++;            // 跳跃步数计数
            left = max_index;  // 更新左边界
            right = max_range; // 更新右边界

        } while (left != right);
        return -1;
    }
};

auto main() -> int
{
    Solution sol;

    // vector<int> nums{2, 3, 1, 1, 4};
    // vector<int> nums{2, 3, 0, 1, 4};
    // vector<int> nums{0};
    // vector<int> nums{1};
    // vector<int> nums{1, 2};
    vector<int> nums{1, 2, 3};

    cout << "count = " << sol.jump(nums) << endl;
}
