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
