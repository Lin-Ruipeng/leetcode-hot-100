#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp{
            {0, 1}};
        int count = 0;
        // 对于[0]元素要特别处理
        if (nums[0] == k)
        {
            count++;
        }
        if (nums[0] == 0)
        {
            mp[0]++;
        }
        else
        {
            mp[nums[0]] = 1;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            // 1. 先求取前缀和
            nums[i] += nums[i - 1];
            // 2. 然后看有无区间存在
            if (mp.count(nums[i] - k))
            {
                count += mp[nums[i] - k];
            }
            // 3. 最后要记得把本次前缀和写入哈希表
            if (mp.count(nums[i]))
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]] = 1;
            }
        }
        return count;
    }
};

auto main() -> int
{
    Solution sol;
    vector<int> nums{1, 2, 3};
    int k = 3;

    cout << "result = " << sol.subarraySum(nums, k) << endl;
}