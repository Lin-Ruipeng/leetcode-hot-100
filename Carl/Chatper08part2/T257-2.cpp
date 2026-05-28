// T257.二叉树的所有路径 层序遍历

#include <stack>
#include <string>
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
  vector<string> binaryTreePaths(TreeNode *root) {
    stack<TreeNode *> treeSt;  // 保存树的遍历节点
    stack<string> pathSt;      // 保存遍历路径的节点
    vector<string> result;     // 保存最终路径的集合
    if (!root) return result;
    treeSt.push(root);
    pathSt.push(to_string(root->val));
    while (!treeSt.empty()) {
      TreeNode *node = treeSt.top();
      treeSt.pop();  // 取出节点 中
      string path = pathSt.top();
      pathSt.pop();  // 取出该节点对应的路径
      if (!node->left && !node->right) {
        // 叶子节点
        result.push_back(path);
      }
      if (node->right) {
        treeSt.push(node->right);  // 右节点
        pathSt.push(path + "->" + to_string(node->right->val));
      }
      if (node->left) {
        treeSt.push(node->left);  // 左节点
        pathSt.push(path + "->" + to_string(node->left->val));
      }
    }
    return result;
  }
};
