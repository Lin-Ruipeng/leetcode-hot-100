// T257.二叉树所有路径 递归回溯法

#include <string>
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
class Solution {
 public:
  void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
    path.push_back(cur->val);
    // 检查叶子节点
    if (!cur->left && !cur->right) {
      string sPath;
      for (int i = 0; i < path.size() - 1; ++i) {
        sPath += to_string(path[i]);
        sPath += "->";
      }
      sPath += to_string(path[path.size() - 1]);
      result.push_back(sPath);
      return;
    }
    if (cur->left) {
      traversal(cur->left, path, result);
      path.pop_back();  // 回溯
    }
    if (cur->right) {
      traversal(cur->right, path, result);
      path.pop_back();  // 回溯
    }
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    vector<int> path;
    if (!root) return result;
    traversal(root, path, result);
    return result;
  }
};
