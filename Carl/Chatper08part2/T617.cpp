// T617.合并二叉树
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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    // 修改root1的数据和结构
    root1->val += root2->val;                               // 中
    root1->left = mergeTrees(root1->left, root2->left);     // 左
    root1->right = mergeTrees(root1->right, root2->right);  // 右
    return root1;
  }
};
