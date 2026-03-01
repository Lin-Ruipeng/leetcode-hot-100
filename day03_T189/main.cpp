#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

// 三次反转!!!

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto &num : nums)
    {
        cout << num << ",";
    }

    Solution sol;
    sol.rotate(nums, 3);

    cout << endl;
    for (const auto &num : nums)
    {
        cout << num << ",";
    }
    return 0;
}