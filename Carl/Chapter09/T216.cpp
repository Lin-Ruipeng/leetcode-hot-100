// T216.组合总和|||

#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> result;  // 存放结果
  vector<int> path;
  void backtracking(int targetSum, int k, int sum, int startIndex) {
    if (path.size() == k) {
      if (sum == targetSum) {
        result.push_back(path);
      }
      return;  // 如果path size为k但是sum不为目标值,直接返回
    }
    for (int i = startIndex; i <= 9; ++i) {
      sum += i;                                // 处理
      path.push_back(i);                       // 处理
      backtracking(targetSum, k, sum, i + 1);  // 处理,注意需要i+1
      sum -= i;                                // 回溯
      path.pop_back();                         // 回溯
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    result.clear();
    path.clear();
    backtracking(n, k, 0, 1);
    return result;
  }
};

// 剪枝优化
class Solution2 {
  vector<vector<int>> result;  // 存放结果
  vector<int> path;
  void backtracking(int targetSum, int k, int sum, int startIndex) {
    // 这一个if是剪枝优化
    if (sum > targetSum) {
      return;  // 现在都大于了,后面的肯定就不用看了
    }
    if (path.size() == k) {
      if (sum == targetSum) {
        result.push_back(path);
      }
      return;  // 如果path size为k但是sum不为目标值,直接返回
    }
    // 剪枝优化,提前结束
    for (int i = startIndex; i <= 9 - (k - path.size()) + 1; ++i) {
      sum += i;                                // 处理
      path.push_back(i);                       // 处理
      backtracking(targetSum, k, sum, i + 1);  // 处理,注意需要i+1
      sum -= i;                                // 回溯
      path.pop_back();                         // 回溯
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    result.clear();
    path.clear();
    backtracking(n, k, 0, 1);
    return result;
  }
};
