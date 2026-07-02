// T47.全排列II

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      // 连续相同元素直接跳
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }
      if (used[i] == false) {
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
      }
    }
  }

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    result.clear();
    path.clear();
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return result;
  }
};
