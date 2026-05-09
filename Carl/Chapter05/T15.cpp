// T15 三数之和

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      // 排序后的第一个元素大于0必定不存在和为0的情况，因为后面的数字更大
      if (nums[i] > 0) {
        return result;
      }
      // 去重,避免两次扫描得到的元素相同
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (right > left) {
        // 去重不能在这里操作,因为可能出现left >= right
        if (nums[i] + nums[left] + nums[right] > 0) {
          right--;
        } else if (nums[i] + nums[left] + nums[right] < 0) {
          left++;
        } else {
          result.push_back(vector<int>{nums[i], nums[left], nums[right]});
          // 在这里去重
          while (right > left && nums[right] == nums[right - 1]) right--;
          while (right > left && nums[left] == nums[left + 1]) left++;
          // 找到答案后必须收缩双指针
          right--;
          left++;
        }
      }
    }
    return result;
  }
};
