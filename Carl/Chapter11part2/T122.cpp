// T122. 买卖股票的最佳时机 II
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] -= prices[0];  // [0]表示当天买入股票
    dp[0][1] = 0;           // [1]表示当天卖出股票
    for (int i = 1; i < len; ++i) {
      // 如果当天买入股票的最大收益:
      // 要么是不操作要么是今天价格比昨天更低了
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      // 如果当天卖出股票的最大收益:
      // 要么是持有要么是今天价格更高卖出了
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[len - 1][1];
  }
};
