// T110.平衡二叉树 层序遍历

#include <algorithm>
#include <stack>

using namespace std;

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
  int getDepth(TreeNode* cur) {
    stack<TreeNode*> st;
    if (cur) st.push(cur);
    int depth = 0;  // 记录深度
    int result = 0;
    while (!st.empty()) {
      TreeNode* node = st.top();
      if (node) {
        st.pop();
        st.push(node);  // 中
        st.push(nullptr);
        ++depth;
        if (node->right) st.push(node->right);  // 右
        if (node->left) st.push(node->left);    // 左
      } else {
        st.pop();
        node = st.top();
        st.pop();
        --depth;
      }
      result = result > depth ? result : depth;
    }
    return result;
  }
  bool isBalanced(TreeNode* root) {
    stack<TreeNode*> st;
    if (!root) return true;
    st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();  // 中序
      st.pop();
      if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
        return false;
      }
      if (node->right) st.push(node->right);  // 右
      if (node->left) st.push(node->left);    // 左
    }
    return true;
  }
};
