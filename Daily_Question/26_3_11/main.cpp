#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int old_n = n;
        int i = 0; // 记录是几位二进制
        if (n == 0)
            i = 1;
        else
            while (n != 0)
            {
                n /= 2;
                i++;
            }
        return pow(2, i) - 1 - old_n;
    }
};

auto main() -> int
{
    int n = 7;

    Solution sol;
    cout << "result = " << sol.bitwiseComplement(n) << endl;
}
