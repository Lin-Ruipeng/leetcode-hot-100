// 416. 分割等和子集

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  // 01背包问题,要找出元素的和为 sum/2
  bool canPartition(vector<int>& nums) {
    int sum = 0;

    vector<int> dp(10001, 0);
    for (auto num : nums) {
      sum += num;
    }
    if (sum % 2) {
      return false;  // 和为奇数永远不可能平分
    }
    int target = sum / 2;

    // 0-1 背包
    for (int i = 0; i < nums.size(); ++i) {
      // 每个元素一定不能重复放入背包,所以用从大到小遍历
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    // 集合中的元素恰好是 sum/2
    if (dp[target] == target) {
      return true;
    }
    return false;
  }
};
