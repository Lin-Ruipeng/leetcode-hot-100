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
