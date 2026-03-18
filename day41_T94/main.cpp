#include <vector>

using namespace std;

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        traverse(root, res);
        return res;
    }

private:
    void traverse(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }

        // 1. 访问左子树
        traverse(root->left, res);
        // 2. 中序访问
        res.push_back(root->val);
        // 3. 访问右子树
        traverse(root->right, res);
    }
};