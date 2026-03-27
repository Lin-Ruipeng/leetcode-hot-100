#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 防止尺寸问题
        if (nums.size() + 1 - k <= 0)
        {
            return {};
        }

        vector<int> res(nums.size() + 1 - k);
        deque<pair<int, int>> window;

        // 递减队列初始化
        for (int i = 0; i < k; i++)
        {
            while (window.size() && window.back().first < nums[i])
            {
                window.pop_back();
            }
            window.push_back({nums[i], i});
        }

        // 开始找窗口最大
        res[0] = window.front().first;
        for (int i = 1; i < res.size(); i++)
        {
            int num = nums[i + k - 1];

            // 需要考虑更新问题(下标太旧的需要被抛弃)
            if (window.front().second == i - 1)
            {
                window.pop_front();
            }
            while (window.size() && window.back().first < num)
            {
                window.pop_back();
            }
            window.push_back({num, i + k - 1});

            res[i] = window.front().first;
        }

        return res;
    }
};

auto main() -> int
{
    cout << "Hello World!" << endl;
}
