
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return isMirror(root->left, root->right);
        }
    }

private:
    bool isMirror(TreeNode *left_tree, TreeNode *right_tree)
    {
        if (left_tree == nullptr && right_tree == nullptr)
        {
            return true;
        }

        if (left_tree == nullptr || right_tree == nullptr)
        {
            // 两者不同时未空,但是有一个为空,肯定不相等
            return false;
        }

        if (left_tree->val != right_tree->val)
        {
            return false;
        }

        return (isMirror(left_tree->left, right_tree->right) && isMirror(left_tree->right, right_tree->left));
    }
};