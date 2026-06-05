// T98.验证搜索二叉树

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 递归法
class Solution {
 public:
  TreeNode *pre = nullptr;  // 用于记录前一个节点
  // 中序遍历检查是不是 升序
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    bool left = isValidBST(root->left);

    if (pre && pre->val >= root->val) return false;
    pre = root;

    bool right = isValidBST(root->right);
    return left && right;
  }
};
