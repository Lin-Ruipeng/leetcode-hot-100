#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;
        }

        // 处理n>2的情况
        // f(n) = f(n-1) + f(n-2)
        int fn_1 = 2;         // f(2) = 2 (n-1)
        int fn_2 = 1;         // f(1) = 1 (n-2)
        int fn = fn_1 + fn_2; // f(3)
        for (int i = 3; i <= n; i++)
        {
            fn = fn_1 + fn_2;
            // 更新
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};

auto main() -> int
{
    Solution sol;
    int n = 4;

    cout << sol.climbStairs(n) << endl;
}
