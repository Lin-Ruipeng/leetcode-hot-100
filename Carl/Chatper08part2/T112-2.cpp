// T112.路径总和 层序遍历法

#include <stack>

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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    // 此时栈内存放的是pair<节点指针, 路径数值>
    stack<pair<TreeNode *, int>> st;
    st.push(pair<TreeNode *, int>(root, root->val));
    while (!st.empty()) {
      pair<TreeNode *, int> node = st.top();
      st.pop();
      // 如果是叶子节点且路径数值等于sum就返回true
      if (!node.first->left && !node.first->right && targetSum == node.second)
        return true;

      // 右侧节点
      if (node.first->right) {
        st.push(pair<TreeNode *, int>(node.first->right,
                                      node.second + node.first->right->val));
      }
      // 左侧节点
      if (node.first->left) {
        st.push(pair<TreeNode *, int>(node.first->left,
                                      node.second + node.first->left->val));
      }
    }
    return false;
  }
};
