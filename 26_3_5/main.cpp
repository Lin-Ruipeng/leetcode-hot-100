#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int num_0 = 0;
        int num_1 = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                {
                    num_1++;
                }
                else
                {
                    num_0++;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    num_1++;
                }
                else
                {
                    num_0++;
                }
            }
        }
        return min(num_0, num_1);
    }
};

auto main() -> int
{
}
