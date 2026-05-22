// T104.二叉树的最大深度
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

// 层序遍历次数就是深度
class Solution {
 public:
  int maxDepth(TreeNode *root) {
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
      }
    }
    return depth;
  }
};

// 递归法
class Solution2 {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
