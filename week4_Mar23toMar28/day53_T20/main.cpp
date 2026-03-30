#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // 1. 奇数个必定假
        if (s.size() % 2)
        {
            return false;
        }
        // 2. 0个直接真
        if (s.size() == 0)
        {
            return true;
        }
        // 3. 开始压栈弹栈
        stack<char> braces;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                braces.push(s[i]);
                break;
            case ')':
                if (braces.empty())
                {
                    return false;
                }
                if (braces.top() == '(')
                {
                    braces.pop(); // 弹栈
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (braces.empty())
                {
                    return false;
                }
                if (braces.top() == '[')
                {
                    braces.pop(); // 弹栈
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (braces.empty())
                {
                    return false;
                }
                if (braces.top() == '{')
                {
                    braces.pop(); // 弹栈
                }
                else
                {
                    return false;
                }
                break;

            default:
                break;
            }
        }

        return braces.empty();
    }
};

auto main() -> int
{
    cout << "Hello World!" << endl;
}
