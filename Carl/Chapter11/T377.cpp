// T377. 组合总和 Ⅳ  代码随想录11.15

#include <vector>
using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    // 遍历背包
    for (int i = 0; i <= target; i++) {
      // 遍历物品
      for (int j = 0; j < nums.size(); j++) {
        if (i - nums[j] >= 0) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    return dp[target];
  }
};
