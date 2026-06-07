// T219.存在重复元素II

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (k == 0) return false;

    // 存储大小为k的滑动窗口中的出现的元素
    unordered_set<int> kset;

    // case 1: 不用滑动窗口时
    if (nums.size() <= k) {
      for (int num : nums) {
        if (kset.find(num) != kset.end()) {
          return true;  // k范围内找到重复!
        } else {
          kset.insert(num);
        }
      }
      return false;
    }

    // case 2: 对于窗口小于总元素时,需要考虑滑动了
    // 2.1 先处理前k个
    for (int i = 0; i < k; ++i) {
      if (kset.find(nums[i]) != kset.end()) {
        return true;  // k范围内找到重复!
      } else {
        kset.insert(nums[i]);
      }
    }
    // 2.2 开始滑动窗口
    for (int i = k; i < nums.size(); ++i) {
      if (kset.find(nums[i]) != kset.end()) {
        return true;
      } else {
        kset.erase(nums[i - k]);
        kset.insert(nums[i]);
      }
    }

    return false;  // 没找到就是假
  }
};
