// T279. 完全平方数
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    // 先遍历物品
    for (int i = 1; i * i <= n; ++i) {
      // 再遍历背包
      for (int j = 1; j <= n; ++j) {
        if (j - i * i >= 0) {
          dp[j] = min(dp[j - i * i] + 1, dp[j]);
        }
      }
    }
    return dp[n];
  }
};
