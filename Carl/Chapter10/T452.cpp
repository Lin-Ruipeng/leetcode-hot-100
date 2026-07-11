// 452. 用最少数量的箭引爆气球
// 代码随想录 10.10
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
  }

 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;
    sort(points.begin(), points.end(), cmp);

    int result = 1;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > points[i - 1][1]) {
        // 注意不是 >= 才会需要第二支才能射到
        result++;
      } else {
        // 取最小右侧边界
        points[i][1] = min(points[i - 1][1], points[i][1]);
      }
    }
    return result;
  };
};
