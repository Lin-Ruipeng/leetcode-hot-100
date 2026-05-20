// T226.反转二叉树(层序遍历)
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
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    queue<TreeNode *> que;
    if (root) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = que.front();
        que.pop();
        swap(node->left, node->right);  // 交换！
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
    }
    return root;
  }
};
