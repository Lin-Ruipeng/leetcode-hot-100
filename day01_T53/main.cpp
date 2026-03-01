#include <iostream>
using namespace std;
/***
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。
 */

/**
 * 解题思路：先考虑局部最大，你只需要考虑前几个元素和是不是大于0，如果小于0，果断舍弃啊，
 * 比如说，1,-2,3那么由于1-2<0那么你干脆全部舍弃掉,直接从3重新开始
 * 但是如果是2,-1,3那么显然就保留下来呗!
 * 最后需要记住,这样获得的是局部的最大最小,你会忘记全局最大最小,比如说:
 * 99,99,-200,1这样你会因为99+99-200<0让局部最大最后等于1
 */

#include <vector>
#include <climits>
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = INT_MIN; // 局部最大
        int maxSum = INT_MIN;  // 全局最大

        for (auto num : nums)
        {
            // 1. 检查局部和是否小于0,小于就需要舍弃掉,否则就保留呗
            if (currSum <= 0)
            {
                currSum = num;
            }
            else
            {
                currSum += num;
            }
            // 2. 更新全局最大值记录
            if (maxSum < currSum)
            {
                maxSum = currSum;
            }
        }
        return maxSum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums = {1};
    // vector<int> nums = {5, 4, -1, 7, 8};
    auto subArraySumMax = sol.maxSubArray(nums);

    cout << "subArraySumMax = " << subArraySumMax << endl;
    return 0;
}
