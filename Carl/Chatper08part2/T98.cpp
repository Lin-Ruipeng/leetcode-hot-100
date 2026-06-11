// T98.验证搜索二叉树

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 递归法
class Solution {
 public:
  TreeNode *pre = nullptr;  // 用于记录前一个节点
  // 中序遍历检查是不是 升序
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    bool left = isValidBST(root->left);

    if (pre && pre->val >= root->val) return false;
    pre = root;

    bool right = isValidBST(root->right);
    return left && right;
  }
};

// 层序遍历法
#include <stack>
using namespace std;
class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;  // 前一个遍历的节点
    while (cur || !st.empty()) {
      if (cur) {
        st.push(cur);
        cur = cur->left;  // 左节点
      } else {
        cur = st.top();  // 中
        st.pop();
        if (pre && cur->val <= pre->val) return false;
        pre = cur;  // 保存上一个

        cur = cur->right;  // 访问右节点
      }
    }
    return true;
  }
};
