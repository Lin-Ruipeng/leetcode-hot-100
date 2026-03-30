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
    int kthSmallest(TreeNode *root, int k)
    {
        int count = k;
        int result = 0;

        return findKthSmallest(root, count, result);
    }

private:
    int findKthSmallest(TreeNode *root, int &count, int &result)
    {
        if (count == 0) // 剪枝
        {
            return result;
        }

        if (root == nullptr)
        {
            return result;
        }

        // 中序遍历
        findKthSmallest(root->left, count, result);
        if (count == 0) // 再次检查剪枝情况,因为左子树遍历的时候很可能就已经找到了
        {
            return result;
        }

        count--;
        result = root->val;

        findKthSmallest(root->right, count, result);

        return result;
    }
};