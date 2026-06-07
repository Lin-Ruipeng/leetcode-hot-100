// 2196.根据描述创建二叉树
#include <iostream>
#include <queue>
#include <unordered_map>
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
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    if (!descriptions.size()) return nullptr;

    int rootValue = descriptions[0][0];  // 根节点的值
    unordered_map<int, TreeNode*> map;
    unordered_map<int, int> mapRoot;
    TreeNode* tempParent = nullptr;
    TreeNode* tempChild = nullptr;

    for (auto descript : descriptions) {
      if (map.find(descript[0]) != map.end()) {
        tempParent = map[descript[0]];  // 存在就直接访问
      } else {
        tempParent = new TreeNode(descript[0]);
        map[descript[0]] = tempParent;  // map里不存在
      }

      if (map.find(descript[1]) != map.end()) {
        tempChild = map[descript[1]];
      } else {
        tempChild = new TreeNode(descript[1]);  // map里不存在
        map[descript[1]] = tempChild;
      }

      // 左右子节点?
      if (descript[2]) {
        tempParent->left = tempChild;
      } else {
        tempParent->right = tempChild;
      }

      // 统计入度
      if (mapRoot.find(descript[0]) == mapRoot.end()) {
        mapRoot[descript[0]] = 0;
      }
      if (mapRoot.find(descript[1]) != mapRoot.end()) {
        ++mapRoot[descript[1]];
      } else {
        mapRoot[descript[1]] = 1;
      }
    }

    // 入度为0的是根节点
    for (const auto [key, value] : mapRoot) {
      if (value == 0) {
        rootValue = key;
      }
    }

    return map[rootValue];
  }
};

// 层序遍历
void printTree(TreeNode* root) {
  if (!root) return;

  queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    size_t size = que.size();
    for (; size; --size) {
      TreeNode* temp = que.front();
      que.pop();

      if (temp->left) {
        que.push(temp->left);
      }

      if (temp->right) {
        que.push(temp->right);
      }

      std::cout << temp->val << " ";
    }
    std::cout << "进入下一层" << std::endl;
  }
}

auto main() -> int {
  Solution sol;

  vector<vector<int>> nums = {
      {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};

  auto root = sol.createBinaryTree(nums);

  printTree(root);

  return 0;
}
