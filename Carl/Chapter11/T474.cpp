// T474.0和1 代码随想录11.12
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (auto str : strs) {  // 遍历物品
      int oneNum = 0, zeroNum = 0;
      for (auto c : str) {
        if (c == '0')
          ++zeroNum;
        else
          ++oneNum;
      }
      // 遍历背包容量 从后往前
      for (int i = m; i >= zeroNum; --i) {
        for (int j = n; j >= oneNum; --j) {
          dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
