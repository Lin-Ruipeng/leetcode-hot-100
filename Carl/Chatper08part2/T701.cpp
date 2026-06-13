// T701.二叉搜索树中的插入操作

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
  TreeNode* parent;
  void traversal(TreeNode* cur, int val) {
    if (!cur) {
      TreeNode* node = new TreeNode(val);
      if (val > parent->val)
        parent->right = node;
      else
        parent->left = node;
      return;
    }
    parent = cur;
    if (cur->val > val) traversal(cur->left, val);
    if (cur->val < val) traversal(cur->right, val);
    return;
  }

 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    parent = new TreeNode(0);
    if (!root) {
      root = new TreeNode(val);
    }
    traversal(root, val);
    return root;
  }
};
