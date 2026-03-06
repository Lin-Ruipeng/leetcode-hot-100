#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero_count = 0;
        int one_count = 0;
        for (const auto &num : nums)
        {
            if (num == 0)
                zero_count++;
            else if (num == 1)
                one_count++;
        }
        for (int i = 0; i < zero_count; i++)
            nums[i] = 0;
        for (int i = zero_count; i < zero_count + one_count; i++)
            nums[i] = 1;
        for (int i = zero_count + one_count; i < nums.size(); i++)
            nums[i] = 2;
    }
};

auto main() -> int
{
    Solution sol;

    vector<int> nums{1, 1, 0, 0, 2, 2, 0, 0, 0, 1, 1, 1};

    sol.sortColors(nums);

    cout << "result: ";
    for (const auto &num : nums)
    {
        cout << num << ",";
    }
    cout << endl;
}
