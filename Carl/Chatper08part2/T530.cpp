// T530.二叉树的元素最小差值
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
