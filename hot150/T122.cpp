// T122.买卖股票的最佳时机II

#include <vector>
using namespace std;

// 贪心就完事了, 明天涨价我就买入卖出

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    vector<int> profit;
    profit.reserve(prices.size() - 1);

    for (int i = 1; i < prices.size(); ++i) {
      profit.push_back(prices[i] - prices[i - 1]);
    }

    int sumProfit = 0;
    for (int num : profit) {
      if (num > 0) sumProfit += num;
    }
    return sumProfit;
  }
};
