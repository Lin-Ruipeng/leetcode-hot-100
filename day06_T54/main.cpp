#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 存储结果
        vector<int> result;
        // 四周限制
        int left_limits = 0;
        int right_limits = matrix[0].size() - 1;
        int top_limits = 0;
        int bottom_limits = matrix.size() - 1;
        // 方向: 0右 1下 2左 3上
        int direction = 0;

        // 扫描
        while (left_limits != right_limits + 1 && top_limits != bottom_limits + 1)
        {

            switch (direction % 4)
            {
            case 0: // 右
                for (int j = left_limits; j <= right_limits; j++)
                {
                    result.push_back(matrix[top_limits][j]);
                }
                top_limits++;
                break;

            case 1: // 下
                for (int i = top_limits; i <= bottom_limits; i++)
                {
                    result.push_back(matrix[i][right_limits]);
                }
                right_limits--;
                break;

            case 2: // 左
                for (int j = right_limits; j >= left_limits; j--)
                {
                    result.push_back(matrix[bottom_limits][j]);
                }
                bottom_limits--;
                break;

            case 3: // 上
                for (int i = bottom_limits; i >= top_limits; i--)
                {
                    result.push_back(matrix[i][left_limits]);
                }
                left_limits++;
                break;
            }
            direction++;
        }

        return result;
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
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    Solution sol;

    cout << "result: [";
    for (auto num : sol.spiralOrder(matrix))
    {
        cout << num << ",";
    }
    cout << "]" << endl;

    return 0;
}