#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 1. 先处理 nullptr
        if (root == nullptr)
        {
            return nullptr;
        }

        // 先递归交换
        invertTree(root->left);
        invertTree(root->right);

        // 再对自己交换
        std::swap(root->left, root->right);

        return root;
    }
};