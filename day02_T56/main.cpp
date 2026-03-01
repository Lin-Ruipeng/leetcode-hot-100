#include <iostream>
using namespace std;

/**
 * 思路：
 * 先排序
 * 然后考虑:[a,b],[c,d]
 * 如果有a<=c<=b,那么说明区间重叠,合并成[a,max(b,d)]
 * 否则说明两个区间无重叠,前一个区间弹出就行
 */

#include <vector>
#include <algorithm> // sort排序

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result; // 存储结果

        // 1. 先排序(sort,使用lambda表达式)
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int> &a, const vector<int> &b)
                  {
                      return a[0] < b[0]; // 升序排序
                  });

        // 注意:必须是排序之后再取[0]
        vector<int> last_interval = intervals[0];

        // 2. 再合并区间
        for (auto interval : intervals)
        {
            // a<=c<=b
            if (last_interval[0] <= interval[0] && interval[0] <= last_interval[1])
            {
                // [a, max(b,d)]
                if (interval[1] > last_interval[1])
                {
                    last_interval[1] = interval[1];
                }
            }
            else
            {
                result.push_back(last_interval);
                last_interval = interval;
            }
        }
        // 注意:出了for循环之后还需要将最后一个push_back
        result.push_back(last_interval);

        return result;
    }
};

int main()
{
    Solution sol;

    // vector<vector<int>> intervals = {
    //     {1, 3},
    //     {2, 6},
    //     {8, 10},
    //     {15, 18}};

    // vector<vector<int>> intervals = {
    //     {1, 4},
    //     {4, 5}};

    vector<vector<int>> intervals = {
        {4, 7},
        {1, 4}};

    cout << "result : " << endl;
    for (const auto &interval : sol.merge(intervals))
    {
        cout << "[" << interval[0] << "," << interval[1] << "],";
    }
    cout << endl;

    return 0;
}
