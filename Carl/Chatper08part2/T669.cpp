// T669.修剪二叉搜索树

// 参考代码随想录8.22

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
// 递归法
class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) {
      return nullptr;
    }
    if (root->val < low) {
      TreeNode* right = trimBST(root->right, low, high);
      return right;
    }
    if (root->val > high) {
      TreeNode* left = trimBST(root->left, low, high);
      return left;
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};
