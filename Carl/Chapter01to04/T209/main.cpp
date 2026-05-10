// T209.长度最小的子数组, 用滑动窗口法
#include <limits>  // 类型最值
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int result = numeric_limits<int>::max();
    int sum = 0;        // 求和
    int i = 0;          // 滑动窗口的起始
    int subLength = 0;  // 窗口长度
    for (int j = 0; j < nums.size(); ++j) {
      sum += nums[j];
      while (sum >= target) {
        subLength = j - i + 1;  // 此时的字串长度
        result = result < subLength ? result : subLength;
        sum -= nums[i++];  // 最巧妙的一步, 同时减sum和增i下标
      }
    }
    // 需要考虑到, 所有的元素加起来都不超过target
    return result == numeric_limits<int>::max() ? 0 : result;
  }
};
