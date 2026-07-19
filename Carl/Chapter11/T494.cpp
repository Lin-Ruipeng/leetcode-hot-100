// T494.目标和

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
    }
    if (abs(target) > sum) {
      return 0;  // 无解
    }
    if ((target + sum) % 2) {
      return 0;  // 无解,数学推导看书11.11
    }
    int bagSize = (target + sum) / 2;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;  // 把容量为0的背包装满只有1种装法
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = bagSize; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[bagSize];
  }
};
