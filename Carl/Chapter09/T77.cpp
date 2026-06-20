// T77.组合

#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> result;  // 存放结果集合
  vector<int> path;            // 存放符合条件的单个结果
  void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex; i <= n; ++i) {
      path.push_back(i);          // 处理节点
      backtracking(n, k, i + 1);  // 递归
      path.pop_back();            // 回溯,撤销处理的节点
    }
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    result.clear();
    path.clear();
    backtracking(n, k, 1);
    return result;
  }
};
