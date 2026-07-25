// T121.买卖股票的最佳时机
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    // [i][0]是第i天买入股票的现金
    // [i][1]是第i天卖出股票的现金(也就是最大收益)
    for (int i = 1; i < len; ++i) {
      // 买入肯定是越低价格买入越好 max比较出哪个花费少
      dp[i][0] = max(dp[i - 1][0], -prices[i]);
      // 卖出肯定是收益越高越好 max比较出当天是持有还是卖出收益更高
      dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
  }
};
