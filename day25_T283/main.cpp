#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 第一个数字是不是0
        int zeroCount = nums[0] ? 0 : 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i]) // 不是0
            {
                swap(nums[i - zeroCount], nums[i]);
            }
            else
            {
                zeroCount++;
            }
        }
    }
};

auto main() -> int
{
    vector<int> nums{0, 2, 0, 3, 4, 5, 0, 0, 6, 7};
    Solution sol;
    cout << "old : ";
    for (const auto &num : nums)
        cout << num << ",";
    cout << endl
         << "new : ";
    sol.moveZeroes(nums);
    for (const auto &num : nums)
        cout << num << ",";
    cout << endl;
}