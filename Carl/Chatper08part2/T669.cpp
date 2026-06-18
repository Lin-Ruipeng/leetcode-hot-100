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

// 层序遍历
class Solution2 {
 public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) {
      return nullptr;
    }

    // 处理头节点,左右都闭区间
    while (root && (root->val < low || root->val > high)) {
      if (root->val < low) {
        root = root->right;  // 小于low遍历右侧
      } else {
        root = root->left;  // 大于high就往左遍历
      }
    }
    TreeNode* cur = root;
    // 此时root已经在[low,high]闭区间内了,处理左子小于low
    while (cur) {
      while (cur->left && cur->left->val < low) {
        cur->left = cur->left->right;
      }
      cur = cur->left;
    }
    cur = root;

    // 再处理右子大于high
    while (cur) {
      while (cur->right && cur->right->val > high) {
        cur->right = cur->right->left;
      }
      cur = cur->right;
    }
    return root;
  }
};
