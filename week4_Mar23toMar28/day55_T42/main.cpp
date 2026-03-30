#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // 1. 记录左右前缀最大值
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        leftMax[0] = height[0];
        rightMax[height.size() - 1] = height[height.size() - 1];
        for (int i = 1; i < height.size(); i++)
        {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }
        for (int i = height.size() - 2; i >= 0; i--)
        {
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }

        // 使用左右的最小值作为雨水平面高度
        int sum = 0;
        for (int i = 0; i < height.size(); i++)
        {
            sum += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};

auto main() -> int
{
    vector<int> height = {4, 2, 0, 3, 2, 5};

    Solution sol;

    cout << "sum = " << sol.trap(height) << endl;
}
