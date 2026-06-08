// T530.二叉树的元素最小差值
#include <climits>
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

// 递归法
class Solution {
 private:
  vector<int> vec;
  void traversal(TreeNode *root) {
    if (!root) return;
    traversal(root->left);
    vec.push_back(root->val);  // 中序
    traversal(root->right);
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    vec.clear();
    traversal(root);
    if (vec.size() < 2) return 0;
    int result = vec[1] - vec[0];
    for (int i = 2; i < vec.size(); ++i) {
      result = min(result, vec[i] - vec[i - 1]);
    }
    return result;
  }
};

// 更省空间的写法
class Solution2 {
 private:
  int result = INT_MAX;
  TreeNode *pre;
  void traversal(TreeNode *cur) {
    if (!cur) return;
    traversal(cur->left);  // 左
    if (pre) result = min(result, cur->val - pre->val);
    pre = cur;              // 记录上一个节点
    traversal(cur->right);  // 右
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    traversal(root);
    return result;
  }
};

// 层序遍历法
class Solution {
 public:
  int getMinimumDifference(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    int result = INT_MAX;
    while (cur || !st.empty()) {
      if (cur) {
        st.push(cur);
        cur = cur->left;  // 左
      } else {
        cur = st.top();
        st.pop();
        if (pre) result = min(result, cur->val - pre->val);  // 中

        pre = cur;
        cur = cur->right;  // 右
      }
    }
    return result;
  }
};
