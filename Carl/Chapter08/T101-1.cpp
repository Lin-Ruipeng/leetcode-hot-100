// T101.对称二叉树：递归法

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
  bool compare(TreeNode *left, TreeNode *right) {
    if (left != nullptr && right != nullptr) {
      if (left->val != right->val)
        return false;
      else
        return compare(left->left, right->right) &&
               compare(left->right, right->left);
    } else if (left == nullptr && right == nullptr) {
      return true;
    }

    return false;
  }
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return compare(root->left, root->right);
  }
};
