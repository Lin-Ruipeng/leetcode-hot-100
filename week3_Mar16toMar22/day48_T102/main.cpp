#include <iostream>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // 0. 没有节点时
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> res;
        int layer = 0;
        DFS(root, res, layer);

        return res;
    }

private:
    void DFS(TreeNode *root, vector<vector<int>> &res, int layer)
    {
        if (root == nullptr)
        {
            return;
        }

        if (layer + 1 > res.size())
        {
            res.resize(layer + 1);
        }
        res[layer].push_back(root->val);

        DFS(root->left, res, layer + 1);
        DFS(root->right, res, layer + 1);
    }
};
auto main() -> int
{
    cout << "Hello World!\n"
         << endl;
}
