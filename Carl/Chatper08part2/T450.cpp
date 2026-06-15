// T450.二叉搜索树删除节点

// 参考代码随想录8.21

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
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    // 情况1没找到
    if (!root) {
      return root;
    }
    if (root->val == key) {
      // 情况2和3,只有一个孩子
      if (!root->left) {
        return root->right;
      } else if (!root->right) {
        return root->left;
      } else {
        // 情况
        TreeNode* cur = root->right;
        while (cur->left) {
          cur = cur->left;
        }
        cur->left = root->left;
        TreeNode* tmp = root;
        root = root->right;
        delete tmp;
        return root;
      }
    }
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    }
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }
};
