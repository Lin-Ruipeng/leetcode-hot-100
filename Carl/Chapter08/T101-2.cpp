// T101.对称二叉树：层序遍历

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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    queue<TreeNode *> que;
    que.push(root->left);  // 左侧子树头节点
    que.push(root->right);
    while (!que.empty()) {
      // 判断是否对称
      TreeNode *leftNode = que.front();
      que.pop();
      TreeNode *rightNode = que.front();
      que.pop();
      // 均空时对称
      if (!leftNode && !rightNode) {
        continue;
      }
      if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
        return false;
      }
      que.push(leftNode->left);
      que.push(rightNode->right);
      que.push(leftNode->right);
      que.push(rightNode->left);
    }
    return true;
  }
};
