#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (const auto &str : strs)
        {
            string order_str = str;
            sort(order_str.begin(), order_str.end());
            if (mp.count(order_str))
            {
                mp[order_str].push_back(str);
            }
            else
            {
                mp[order_str] = {str};
            }
        }

        vector<vector<string>> result;
        for (const auto &[k, v] : mp)
        {
            result.push_back(v);
        }
        return result;
    }
};

auto main() -> int
{
}
