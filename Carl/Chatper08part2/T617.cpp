// T617.合并二叉树
#include <queue>
using namespace std;

// 递归法
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

// 层序遍历法
class Solution2 {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    queue<TreeNode *> que;
    que.push(root1);
    que.push(root2);
    while (!que.empty()) {
      TreeNode *node1 = que.front();
      que.pop();
      TreeNode *node2 = que.front();
      que.pop();
      // 两个节点一定不为空 相加
      node1->val += node2->val;

      // 如果两个左节点都不为空，则加入队列
      if (node1->left != nullptr && node2->left != nullptr) {
        que.push(node1->left);
        que.push(node2->left);
      }
      // 两个右节点一样的操作
      if (node1->right != nullptr && node2->right != nullptr) {
        que.push(node1->right);
        que.push(node2->right);
      }
      // 左节点一空一有(如果是root2没有root1有,那么就不用处理,因为最后也是返回root1)
      if (node1->left == nullptr && node2->left != nullptr) {
        node1->left = node2->left;
      }
      // 右节点一空一有
      if (node1->right == nullptr && node2->right != nullptr) {
        node1->right = node2->right;
      }
    }
    return root1;
  }
};
