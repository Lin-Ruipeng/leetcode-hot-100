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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        int layer = 0;
        DFS(root, res, layer);
        return res;
    }

private:
    void DFS(TreeNode *root, vector<int> &res, int layer)
    {
        if (root == nullptr)
        {
            return;
        }

        if (res.size() < layer + 1)
        {
            res.resize(layer + 1);
            res[layer] = root->val;
        }

        DFS(root->right, res, layer + 1);
        DFS(root->left, res, layer + 1);
    }
};

auto main() -> int
{
    cout << "Hello World!\n"
         << endl;
}
