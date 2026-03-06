#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        if (nums[left] < nums[right])
        {
            return nums[left];
        }

        while (left + 1 < right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] > nums[left])
            {
                left = middle;
            }
            else
            {
                right = middle;
            }
        }

        return nums[right];
    }
};

auto main() -> int
{
    Solution sol;

    vector<int> nums{4, 5, 6, 7, 0, 1, 2};

    cout << "min = " << sol.findMin(nums) << endl;
}
