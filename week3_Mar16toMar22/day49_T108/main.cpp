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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return childNode(0, nums.size() - 1, nums);
    }

private:
    TreeNode *childNode(int left, int right, vector<int> &nums)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = (left + right) / 2;
        auto *root = new TreeNode(nums[mid]);

        root->left = childNode(left, mid - 1, nums);
        root->right = childNode(mid + 1, right, nums);

        return root;
    }
};
auto main() -> int
{
    cout << "Hello World!" << endl;
}
