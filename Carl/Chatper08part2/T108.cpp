// 108. 将有序数组转换为二叉搜索树

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
  TreeNode* traversal(vector<int>& nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = left + ((right - left) / 2);
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = traversal(nums, left, mid - 1);
    root->right = traversal(nums, mid + 1, right);
    return root;
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = traversal(nums, 0, nums.size() - 1);
    return root;
  }
};

// 层序遍历
#include <queue>
class Solution2 {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) {
      return nullptr;
    }

    TreeNode* root = new TreeNode(0);  // 根节点
    queue<TreeNode*> nodeQue;          // 遍历的节点
    queue<int> leftQue;                // 左区间下标
    queue<int> rightQue;               // 右区间下标
    nodeQue.push(root);                // 先从根节点开始
    leftQue.push(0);                   // 左边从0开始
    rightQue.push(nums.size() - 1);    // 右边从最大开始

    while (!nodeQue.empty()) {
      TreeNode* curNode = nodeQue.front();
      nodeQue.pop();
      int left = leftQue.front();
      leftQue.pop();
      int right = rightQue.front();
      rightQue.pop();
      int mid = left + ((right - left) / 2);

      curNode->val = nums[mid];

      if (left <= mid - 1) {
        curNode->left = new TreeNode(0);
        nodeQue.push(curNode->left);
        leftQue.push(left);
        rightQue.push(mid - 1);
      }

      if (right >= mid + 1) {
        curNode->right = new TreeNode(0);
        nodeQue.push(curNode->right);
        leftQue.push(mid + 1);
        rightQue.push(right);
      }
    }
    return root;
  }
};
