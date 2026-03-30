#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        // 记录开头连续的1是否已经结束
        bool stop_flag = false;

        for (const auto &c : s)
        {
            // 还处在开头连续的1
            if (!stop_flag)
            {
                if (c == '0')
                {
                    stop_flag = true;
                }
            }
            else
            {
                // 开头连续1已经结束了
                if (c == '1')
                {
                    // 又遇到1了,那就为假了
                    return false;
                }
            }
        }
        return true;
    }
};

auto main() -> int
{
    string s = "1101";

    Solution sol;

    cout << "result: " << sol.checkOnesSegment(s) << endl;
}
