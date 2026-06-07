// T1022.根到叶的二进制数之和

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
  int result;
  void traversal(TreeNode *root, int num) {
    if (!root->left && !root->right) {
      result += ((num << 1) | root->val);
    }

    if (root->left) {
      traversal(root->left, (num << 1) | root->val);
    }

    if (root->right) {
      traversal(root->right, (num << 1) | root->val);
    }
  }

 public:
  int sumRootToLeaf(TreeNode *root) {
    if (!root) return 0;

    result = 0;
    traversal(root, 0);
    return result;
  }
};
