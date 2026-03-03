#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 1. 竖直翻转
        for (int i = 0; i < matrix.size() / 2; i++)
        {
            swap(matrix[i], matrix[matrix.size() - 1 - i]);
        }

        // 2. 对角线翻转
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i + 1; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{

    // vector<vector<int>> matrix = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    // };

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution sol;

    sol.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}