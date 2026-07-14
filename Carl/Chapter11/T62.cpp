// T62. 不同路径

#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // 这里解释: dp记录的是走法数不是步数!
    // 所以你一直沿着直线走可不就是走法永远为1么
    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int j = 0; j < n; ++j) dp[0][j] = 1;
    // 开始DP
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};
