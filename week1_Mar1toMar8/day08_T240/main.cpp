#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // 1. 从最右上角开始
        int i = 0;
        int j = matrix[0].size() - 1;

        // 2. 搜索
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        // 3. 没搜到就是没有
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int target = 5;

    Solution sol;

    if (sol.searchMatrix(matrix, target))
        cout << "True";
    else
        cout << "False";

    return 0;
}