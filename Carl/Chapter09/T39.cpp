// T39.组合总和

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& candidates, int target, int sum,
                    int startIndex) {
    if (sum == target) {
      result.push_back(path);
      return;
    }

    // 剪枝优化: 如果sum+candidates[i] > target就终止
    for (int i = startIndex;
         i < candidates.size() && sum + candidates[i] <= target; ++i) {
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracking(candidates, target, sum, i);
      sum -= candidates[i];
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    result.clear();
    path.clear();
    std::sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return result;
  }
};
