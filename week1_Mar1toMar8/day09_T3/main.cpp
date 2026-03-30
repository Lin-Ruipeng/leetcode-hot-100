#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        int left = 0;
        int right = 0;

        while (right != s.size())
        {
            for (int i = left; i < right; i++)
            {
                if (s[right] == s[i])
                {
                    left = i + 1;
                    break;
                }
            }

            if (maxLength < right + 1 - left)
            {
                maxLength = right + 1 - left;
            }

            right++;
        }

        return maxLength;
    }
};

auto main() -> int
{
    // std::string s = "abcabcbb";
    std::string s = "bbbbb";

    Solution sol;

    cout << "s: \t" << s << endl
         << "Length:\t" << sol.lengthOfLongestSubstring(s) << endl;
}
