// T59.螺旋矩阵II

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startx = 0, starty = 0;  // 每次循环的左上角起始坐标
    int loop = n / 2;            // 转圈循环次数
    int mid = n / 2;             // 矩阵的中间位置
    int count = 1;               // 递增赋值
    int offset = 1;              // 控制每一条边遍历的长度
    int i, j;

    while (loop--) {
      i = startx;
      j = starty;

      // 向右
      for (j = starty; j < starty + n - offset; ++j) {
        res[startx][j] = count++;
      }
      // 向下
      for (i = startx; i < startx + n - offset; ++i) {
        res[i][j] = count++;
      }
      // 向左
      for (; j > starty; --j) {
        res[i][j] = count++;
      }
      // 向上
      for (; i > startx; --i) {
        res[i][j] = count++;
      }

      // 下一圈
      startx++;
      starty++;
      offset += 2;  // 一圈收窄2个行或列
    }
    // 还要考虑奇数有一个最中间的数字!
    if (n % 2) {
      res[mid][mid] = count;
    }
    return res;
  }
};
