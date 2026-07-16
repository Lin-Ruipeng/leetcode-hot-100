// T343.整数拆分

#include <algorithm>
#include <vector>
using namespace std;

// 动态规划
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j < i - 1; ++j) {
        dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});
      }
    }
    return dp[n];
  }
};

// 贪心: 拆成3的结果一定最大
class Solution2 {
 public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    int result = 1;
    while (n > 4) {
      result *= 3;
      n -= 3;
    }
    return result * n;
  }
};
