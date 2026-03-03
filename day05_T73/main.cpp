#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // step.1 扫描0元素
        // 为了避免[0][0]不确定是指行0还是列0还是行列均0
        // 先考虑第0行第0列本身有无0,然后排除第0行和第0列进行扫描
        int flag00 = 0;
        if (matrix[0][0] == 0)
        {
            // 行列都要置零
            flag00 = 2;
        }
        else
        {
            // 扫描0行
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[0][j] == 0)
                {
                    // 1 表示第0行需要置零
                    flag00 = 1;
                    break;
                }
            }
            // 扫描0列
            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][0] == 0)
                {
                    if (flag00 == 0)
                    {
                        // -1 只有列需要置零
                        flag00 = -1;
                    }
                    else
                    {
                        // 2 行列都需要置零
                        flag00 = 2;
                    }
                    break;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                // 检查置零
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // step.2 置零
        // 一定要考虑到matrix[0][0]==0时会导致全0
        // 所以两次搜索都避开[0][0]
        // 第0列扫描,先找出需要置零的行(避开[0][0])
        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                // 不用从0列开始
                for (int j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 第0行扫描,找出要置零的列(避开[0][0])
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
            {
                // 不用处理第0行
                for (int i = 1; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 单独处理[0][0]
        // 行置零
        if (flag00 == 1 || flag00 == 2)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[0][j] = 0;
            }
        }
        // 列置零
        if (flag00 == -1 || flag00 == 2)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{

    // vector<vector<int>> matrix = {
    //     {1, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1},
    // };
    // 答案 [[1,0,1],[0,0,0],[1,0,1]]

    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5},
    };
    // 答案 [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

    // vector<vector<int>> matrix = {
    //     {0, 1, 2, 0},
    //     {3, 4, 5, 2},
    //     {1, 3, 1, 5},
    //     {0, 3, 1, 5},
    //     {1, 3, 1, 5},
    // };
    // 测试

    // vector<vector<int>> matrix = {
    //     {1, 0}};

    // vector<vector<int>> matrix = {
    //     {1, 2, 3, 4},
    //     {5, 0, 7, 8},
    //     {0, 10, 11, 12},
    //     {13, 14, 15, 0},
    // };

    // vector<vector<int>> matrix = {
    //     {-4, -2147483648, 6, -7, 0},
    //     {-8, 6, -8, -6, 0},
    //     {2147483647, 2, -9, -6, -10},

    // };

    Solution sol;
    sol.setZeroes(matrix);

    cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}