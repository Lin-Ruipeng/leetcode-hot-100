// T111.二叉树的最小深度

#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 层序遍历法
class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    int depth = 0;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      ++depth;
      for (int i = 0; i < size; ++i) {
        TreeNode *node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
        if (!node->left && !node->right) {
          return depth;  // 左右孩子都空那不就是找到了最浅层的叶子节点了么
        }
      }
    }
    return depth;
  }
};

// 递归法
class Solution2 {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    if (!root->left && root->right) return 1 + minDepth(root->right);
    if (root->left && !root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
  }
};
