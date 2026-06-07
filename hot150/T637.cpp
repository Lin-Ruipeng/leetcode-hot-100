// T637.二叉树的层平均值

#include <queue>
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
  vector<double> averageOfLevels(TreeNode *root) {
    // 边界, 传入为空
    if (!root) return {};

    // 直接层序遍历就完事了
    vector<double> result;
    queue<TreeNode *> que;
    que.push(root);
    int lastSize = 1;
    while (!que.empty()) {
      int size = que.size();
      long sum = 0;
      lastSize = size;
      while (size) {
        // 取出节点
        TreeNode *cur = que.front();
        que.pop();
        // 然后访问节点
        sum += cur->val;
        // 接着进行子节点扫描
        if (cur->left) {
          que.push(cur->left);
        }
        if (cur->right) {
          que.push(cur->right);
        }
        --size;
      }
      result.push_back((double)sum / (double)lastSize);
    }
    return result;
  }
};
