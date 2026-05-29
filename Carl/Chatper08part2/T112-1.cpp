// T112.路径总和 递归法回溯

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
 public:
  bool traversal(TreeNode *cur, int count) {
    // 遇到叶子节点并且计数为0说明找到了, 不要从头加而是用减法到0更好判定
    if (!cur->left && !cur->right && count == 0) return true;
    if (!cur->left && !cur->right) return false;  // 叶子节点直接返回
    if (cur->left) {
      // 注意这里藏了回溯逻辑, 就是假设左节点为真那么count需要减去当前值
      return traversal(cur->left, count - cur->left->val);
      // 如果左节点为假就需要把减去的count加回来,
      // 但是用参数传递时就不会改变count, 所以自动回溯了
    }
    if (cur->right) {
      return traversal(cur->right, count - cur->right->val);
    }
    return false;
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    return traversal(root, targetSum - root->val);
  }
};
