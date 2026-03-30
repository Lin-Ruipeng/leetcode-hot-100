#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // 先算在哪一行
        int left = -1;
        int right = matrix.size();
        int row;

        while (left + 1 < right)
        {
            int middle = (left + right) / 2;
            if (matrix[middle][0] == target)
            {
                return true;
            }
            else if (matrix[middle][0] > target)
            {
                right = middle;
            }
            else
            {
                left = middle;
            }
        }
        row = left;

        if (row < 0)
        {
            return false;
        }

        // 对行内进行二分查找
        left = 0;
        right = matrix[0].size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (matrix[row][middle] == target)
            {
                return true;
            }
            else if (matrix[row][middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return false;
    }
};

auto main() -> int
{
    vector<vector<int>> matrix{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
    };
    int target = 3;

    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;
}
