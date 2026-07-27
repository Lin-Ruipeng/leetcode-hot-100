// T123. 买卖股票的最佳时机 III
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // 一共有五种状态
    // 1.不操作 2.第一次买入 3.第一次卖出 4.第二次买入 5.第二次卖出
    if (prices.size() == 0) {
      return 0;
    }
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    dp[0][1] = -prices[0];  // 第一次买入
    // 第二次买入, 就是这里都第二次买入了, 那么全局只买卖一轮
    dp[0][3] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
      dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }

    return dp[prices.size() - 1][4];
  }
};
