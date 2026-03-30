#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = -1;
        int right = nums.size();
        while (left + 1 < right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] >= target)
            {
                right = middle;
            }
            else
            {
                left = middle;
            }
        }

        return left + 1;
    }
};

auto main() -> int
{
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << sol.searchInsert(nums, target) << endl;
}
