// 746. 使用最小花费爬楼梯

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    // 因为最后一步不用花体力,所以加上去了要减回去
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
  }
};

// 空间优化版本
class Solution2 {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int dp0 = cost[0];
    int dp1 = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
      int dpi = min(dp0, dp1) + cost[i];
      dp0 = dp1;
      dp1 = dpi;
    }
    // 因为最后一步不用花体力,所以加上去了要减回去
    return min(dp0, dp1);
  }
};
