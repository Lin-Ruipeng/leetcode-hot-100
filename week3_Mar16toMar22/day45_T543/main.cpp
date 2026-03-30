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
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int maxDiameter = 0;
        maxDepth(root, maxDiameter);
        return maxDiameter;
    }

private:
    int maxDepth(TreeNode *root, int &maxDiameter)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left_depth = maxDepth(root->left, maxDiameter);
        int right_depth = maxDepth(root->right, maxDiameter);

        if (maxDiameter < left_depth + right_depth)
        {
            maxDiameter = left_depth + right_depth;
        }

        return std::max(left_depth, right_depth) + 1;
    }
};