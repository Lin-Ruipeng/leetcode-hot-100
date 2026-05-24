// T110.平衡二叉树 递归法

#include <algorithm>

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
  // 返回以该节点为根节点的二叉树的高度,如果不是二叉搜索树返回-1
  int getDepth(TreeNode *node) {
    if (!node) return 0;
    int leftDepth = getDepth(node->left);
    if (leftDepth == -1) return -1;
    int rightDepth = getDepth(node->right);
    if (rightDepth == -1) return -1;
    return abs(leftDepth - rightDepth) > 1 ? -1
                                           : 1 + max(leftDepth, rightDepth);
  }
  bool isBalanced(TreeNode *root) { return getDepth(root) != -1; }
};
