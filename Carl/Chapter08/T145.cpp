// T145.二叉树的后序遍历
#include <algorithm>
#include <stack>
#include <vector>

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
  vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> result;
    if (root == nullptr) return result;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      result.push_back(node->val);
      // 和前序相比，这里改入栈顺序
      if (node->left) st.push(node->left);
      if (node->right) st.push(node->right);
    }
    // 最后需要将顺序反转才是后序
    reverse(result.begin(), result.end());
    return result;
  }
};
