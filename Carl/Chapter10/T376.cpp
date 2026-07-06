// T376.摆动序列

#include <vector>

class Solution {
 public:
  int wiggleMaxLength(std::vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }
    int curDiff = 0;  // 差值
    int preDiff = 0;  // 前一个差值
    int result = 1;   // 峰值个数
    for (int i = 0; i < nums.size() - 1; ++i) {
      curDiff = nums[i + 1] - nums[i];
      // 峰值
      if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
        result++;
        preDiff = curDiff;
      }
    }
    return result;
  }
};
