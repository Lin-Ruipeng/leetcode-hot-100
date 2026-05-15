// T42.接雨水 动态规划

// 优化思路：你一侧到另一侧找当前位置的最大高度这个过程可以优化，
// 不是每次都从头开始扫描，而是可以：maxLeft[i] = max(height[i], maxLeft[i-1])

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    if (size < 2) return 0;
    vector<int> maxLeft(size, 0);
    vector<int> maxRight(size, 0);

    // 记录每个柱子的左边的最大高度
    maxLeft[0] = height[0];
    for (int i = 1; i < size; ++i) {
      maxLeft[i] = max(height[i], maxLeft[i - 1]);
    }
    // 记录每个柱子的右边的最大高度
    maxRight[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; --i) {
      maxRight[i] = max(height[i], maxRight[i + 1]);
    }
    // 求和
    int sum = 0;
    for (int i = 0; i < size; ++i) {
      int count = min(maxLeft[i], maxRight[i]) - height[i];
      if (count > 0) sum += count;
    }
    return sum;
  }
};
