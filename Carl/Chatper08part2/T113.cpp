// T113.路径总和II

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;
  // 递归函数不需要返回值, 因为要遍历整棵树
  void traversal(TreeNode *cur, int count) {
    // 遇到叶子节点且找到了和为sum的路径
    if (!cur->left && !cur->right && count == 0) {
      result.push_back(path);
      return;
    }
    // 遇到叶子节点且没有找到合适的边, 直接返回
    if (!cur->left && !cur->right) return;

    // 左侧
    if (cur->left) {
      path.push_back(cur->left->val);
      // 回溯查找子层
      traversal(cur->left, count - cur->left->val);
      path.pop_back();  // 回溯
    }
    // 右侧
    if (cur->right) {
      path.push_back(cur->right->val);
      traversal(cur->right, count - cur->right->val);
      path.pop_back();
    }
    return;
  }

 public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    result.clear();
    path.clear();
    if (!root) return result;
    path.push_back(root->val);  // 放入根节点
    traversal(root, targetSum - root->val);
    return result;
  }
};
