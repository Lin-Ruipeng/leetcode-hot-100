#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int rowNum = 1; rowNum <= numRows; rowNum++)
        {
            res.push_back(generateRow(res, rowNum));
        }
        return res;
    }

private:
    vector<int> generateRow(vector<vector<int>> &res, int rowNum)
    {
        vector<int> row(rowNum);
        for (int i = 0; i < rowNum; i++)
        {
            if (i == 0 || i == rowNum - 1)
            {
                row[i] = 1;
                continue;
            }
            row[i] = res[rowNum - 2][i - 1] + res[rowNum - 2][i];
        }
        return row;
    }
};

auto main() -> int
{
    cout << "Hello World!" << endl;
}
