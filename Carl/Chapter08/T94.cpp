// T94.二叉树的中序遍历
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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != nullptr || !st.empty()) {
      if (cur != nullptr) {
        // 指针访问到最底层
        st.push(cur);
        cur = cur->left;  // 左
      } else {
        // 从栈中弹出的数据就是要处理的数据
        cur = st.top();
        st.pop();
        result.push_back(cur->val);  // 中
        cur = cur->right;            // 右
      }
    }
    return result;
  }
};
