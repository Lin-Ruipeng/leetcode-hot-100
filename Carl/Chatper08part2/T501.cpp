// T501.二叉搜索树里的众数

#include <vector>
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

// 递归法
class Solution {
 private:
  int maxCount;  // 最大频率
  int count;     // 统计频率
  TreeNode* pre;
  vector<int> result;
  void searchBST(TreeNode* cur) {
    if (!cur) return;

    searchBST(cur->left);

    if (!pre) {
      count = 1;
    } else if (pre->val == cur->val) {
      ++count;
    } else {
      count = 1;  // 与前一个节点不同!
    }
    pre = cur;

    if (count == maxCount) {
      result.push_back(cur->val);
      // 多个频率相同的众数都要保留!
    }

    // 发现了比以前频率更高的数据
    if (count > maxCount) {
      maxCount = count;
      result.clear();  // 清除原来的记录

      result.push_back(cur->val);
    }

    // 保持中序遍历这个搜索树,升序访问
    searchBST(cur->right);

    return;
  }

 public:
  vector<int> findMode(TreeNode* root) {
    count = 0;
    maxCount = 0;
    TreeNode* pre = nullptr;
    result.clear();

    searchBST(root);
    return result;
  }
};

// 迭代法
#include <stack>
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    int maxCount = 0;  // 最大频率
    int count = 0;     // 统计频率
    vector<int> result;
    while (cur || !st.empty()) {
      if (cur) {
        st.push(cur);     // 访问节点入栈
        cur = cur->left;  // 左
      } else {
        cur = st.top();  // 中
        st.pop();
        if (pre == nullptr) {
          count = 1;
        } else if (pre->val == cur->val) {
          ++count;
        } else {
          count = 1;  // 与前一个节点不同
        }
        if (count == maxCount) {
          result.push_back(cur->val);
        }

        if (count > maxCount) {
          maxCount = count;
          result.clear();

          result.push_back(cur->val);
        }
        pre = cur;
        cur = cur->right;  // 右
      }
    }
    return result;
  }
};
