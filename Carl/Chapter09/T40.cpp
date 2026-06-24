// T40.组合总和II

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& candidates, int target, int sum,
                    int startIndex, vector<bool>& used) {
    if (sum == target) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex;
         i < candidates.size() && sum + candidates[i] <= target; ++i) {
      // used[i-1]说明是否使用过i-1的元素,以此考虑跳过
      if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
        continue;
      }
      sum += candidates[i];
      path.push_back(candidates[i]);
      used[i] = true;
      backtracking(candidates, target, sum, i + 1, used);
      used[i] = false;
      sum -= candidates[i];
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<bool> used(candidates.size(), false);
    path.clear();
    result.clear();
    std::sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used);
    return result;
  }
};
