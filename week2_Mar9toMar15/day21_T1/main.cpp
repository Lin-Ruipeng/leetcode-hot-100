#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果互补元素存在
            if (mp.count(target - nums[i]))
            {
                return {mp[target - nums[i]], i};
            }
            else
            {
                // 否则就存入元素
                mp[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};

auto main() -> int
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    Solution sol;

    cout << "[";
    for (auto index : sol.twoSum(nums, target))
    {
        cout << index << ',';
    }
    cout << "]" << endl;
}
