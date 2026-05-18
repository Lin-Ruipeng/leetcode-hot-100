// T102. 二叉树的层序遍历

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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> que;
    if (root != nullptr) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
      int size = que.size();  // 就是下一层的size
      vector<int> vec;
      // 一定要使用固定大小的size, 因为que.size是变化的!
      for (int i = 0; i < size; ++i) {
        TreeNode *node = que.front();
        que.pop();
        vec.push_back(node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      result.push_back(vec);
    }
    return result;
  }
};
