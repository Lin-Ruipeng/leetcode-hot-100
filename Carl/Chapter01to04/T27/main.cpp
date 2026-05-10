// T27.移除元素
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
      // 快指针一旦检测到val就直接跳过!
      if (val != nums[fastIndex]) {
        nums[slowIndex++] = nums[fastIndex];
      }
    }
    return slowIndex;
  }
};
