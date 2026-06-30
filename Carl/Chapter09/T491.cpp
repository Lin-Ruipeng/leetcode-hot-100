// T491.非递减子序列
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& nums, int startIndex) {
    if (path.size() > 1) {
      result.push_back(path);
    }
    int used[201] = {0};  // 因为范围是[-100,100]
    for (int i = startIndex; i < nums.size(); ++i) {
      if ((!path.empty() && nums[i] < path.back()) ||
          used[nums[i] + 100] == 1) {
        continue;
      }
      used[nums[i] + 100] = 1;
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
  }
};
