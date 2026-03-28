#include <iostream>
#include <algorithm>

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
    void flatten(TreeNode *root)
    {
        // 左孩子的最右，右孩子
        TreeNode *leftRightChild = nullptr;
        TreeNode *rightChild = nullptr;
        while (root != nullptr)
        {
            if (root->left)
            {
                // 找左子树的最右节点
                leftRightChild = root->left;
                while (leftRightChild->right)
                {
                    leftRightChild = leftRightChild->right;
                }

                // 存一下右子树
                rightChild = root->right;

                // 左子树替换原来的右子树
                root->right = root->left;
                root->left = nullptr;

                // 左子树的最右侧端点连接上右子树
                leftRightChild->right = rightChild;
            }

            root = root->right;
        }
    }
};

auto main() -> int
{
    cout << "Hello World!" << endl;
}
