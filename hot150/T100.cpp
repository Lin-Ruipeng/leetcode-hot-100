// T100.相同的树

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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    else if (!q || !p)
      return false;

    // 1. 都是叶子节点的时候进行判定
    if (!p->left && !q->left && !p->right && !q->right) {
      return p->val == q->val;
    }

    bool flagLeft = true, flagRight = true;

    // 2. 左侧节点进行判定
    if (p->left && q->left) {
      if (p->val == q->val)
        flagLeft = isSameTree(p->left, q->left);
      else
        return false;
    } else if (!p->left && !q->left) {
      flagLeft = true;
    } else {
      return false;
    }

    // 3. 右侧节点进行判定
    if (p->right && q->right) {
      if (p->val == q->val)
        flagRight = isSameTree(p->right, q->right);
      else
        return false;
    } else if (!p->right && !q->right) {
      flagRight = true;
    } else {
      return false;
    }

    return flagLeft && flagRight;
  }
};
