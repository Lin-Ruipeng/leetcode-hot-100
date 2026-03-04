#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        // 记录哪些 行和 列和 为1
        // 特殊位置必定行和列和均1
        // 但是反之不成立,所以需要另外检查
        vector<int> row_eq_1;
        vector<int> column_eq_1;

        // 遍历每行,求取行和
        for (int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                sum += mat[i][j];
            }
            if (sum == 1)
            {
                row_eq_1.push_back(i);
            }
        }

        // 再求取列和
        for (int j = 0; j < mat[0].size(); j++)
        {
            int sum = 0;
            for (int i = 0; i < mat.size(); i++)
            {
                sum += mat[i][j];
            }
            if (sum == 1)
            {
                column_eq_1.push_back(j);
            }
        }

        // 将sum==1的行列交叉点求和,就是答案
        int sum = 0;
        for (const auto &i : row_eq_1)
        {
            for (const auto &j : column_eq_1)
            {
                sum += mat[i][j];
            }
        }

        return sum;
    }
};

auto main() -> int
{
    // vector<vector<int>> matrix{
    //     {1, 0, 0},
    //     {0, 0, 1},
    //     {0, 1, 0},
    // };

    vector<vector<int>> matrix{
        {0, 0, 0, 0, 0, 1, 0, 0}, // 1 --
        {0, 0, 0, 0, 1, 0, 0, 1}, // 2
        {0, 0, 0, 0, 1, 0, 0, 0}, // 1 --
        {1, 0, 0, 0, 1, 0, 0, 0}, // 2
        {0, 0, 1, 1, 0, 0, 0, 0}, // 2
        //  [1, 0, 1, 1, 3, 1, 0, 1]
        //  [-     -  -     -     -]
    };

    Solution sol;

    cout << sol.numSpecial(matrix) << endl;
}
