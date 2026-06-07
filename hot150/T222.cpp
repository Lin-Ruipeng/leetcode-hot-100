// T222.完全二叉树的节点个数

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
  int countNodes(TreeNode *root) {
    if (!root) return 0;

    // 思路就是二分查找最底层哪一个开始是null!
    int depth = 0;  // 树的深度
    TreeNode *head = root;
    while (head) {
      ++depth;
      head = head->left;
    }

    if (depth == 1) return 1;

    // 把右侧是闭区间的情况排除
    head = root;
    int temp = depth;
    while (--temp) {
      head = head->right;
    }
    // 连最最右侧的叶子节点都存在, 那么就是完满的二叉树
    if (head) return (1 << depth) - 1;

    // 确定二分查找范围
    int left = 0, right = (1 << (depth - 1)) - 1;
    while (left + 1 != right) {
      int mid = left + (right - left) / 2;
      head = root;
      for (int i = depth - 2; i >= 0; --i) {
        if (mid & (1 << i)) {
          head = head->right;
        } else {
          head = head->left;
        }
      }
      if (head) {
        left = mid;
      } else {
        right = mid;
      }
    }

    return (1 << (depth - 1)) + left;
  }
};
