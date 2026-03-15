#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_reach = 0;
        int reach_index_left = 0;
        int reach_index_right = 0;

        if (nums.size() == 1)
            return true;

        do
        {
            cout << "L = " << reach_index_left << " R = " << reach_index_right << endl;

            for (int i = reach_index_left; i <= reach_index_right; i++)
            {
                if (i + nums[i] > max_reach)
                {
                    max_reach = i + nums[i];
                    if (max_reach + 1 >= nums.size())
                        return true;
                }
            }

            reach_index_left = reach_index_right;
            reach_index_right = max_reach;
        } while (reach_index_left < reach_index_right);

        return false;
    }
};

auto main() -> int
{
    // vector<int> nums{2,3,1,1,4};
    // vector<int> nums{1, 2, 3};
    // vector<int> nums{0};
    vector<int> nums{3, 2, 1, 0, 4};

    Solution sol;

    if (sol.canJump(nums))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
