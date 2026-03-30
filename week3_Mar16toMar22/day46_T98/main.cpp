
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
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        // 指向上一个节点
        TreeNode *prev = nullptr;

        // 1. 中序遍历,升序即可
        return check(root, prev);
    }

private:
    bool check(TreeNode *root, TreeNode *&prev)
    {
        if (root == nullptr)
        {
            return true;
        }

        // 1. 中序遍历,先左,再访问自己,最后访问右侧
        if (check(root->left, prev) == false)
        {
            return false;
        }

        if (prev != nullptr && root->val <= prev->val)
        {
            // 不严格升序
            return false;
        }

        // 不论如何都需要记录成上一个节点
        prev = root;

        if (check(root->right, prev) == false)
        {
            return false;
        }

        return true;
    }
};