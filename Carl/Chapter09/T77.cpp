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

// 进一步剪枝优化(参考代码随想录9.2)
class Solution2 {
  vector<vector<int>> result;  // 存放结果集合
  vector<int> path;            // 存放符合条件的单个结果
  void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
      result.push_back(path);
      return;
    }
    // 此处进行优化,因为你要考虑k=n=4的时候,你第一层for的starIndex只有为1的时候才有意义
    // 后面的三次迭代都没意义,因为剩余元素都不够了,完全无法产生新的组合
    for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {
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
