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
