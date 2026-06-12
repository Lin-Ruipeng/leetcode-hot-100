// T235.二叉搜索树最近公共祖先

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
    if (!cur) return cur;
    // 中
    if (cur->val > p->val && cur->val > q->val) {
      TreeNode* left = traversal(cur->left, p, q);
      if (left) return left;
    }
    // 右
    if (cur->val < p->val && cur->val < q->val) {
      TreeNode* right = traversal(cur->right, p, q);
      if (right) return right;
    }
    return cur;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return traversal(root, p, q);
  }
};
