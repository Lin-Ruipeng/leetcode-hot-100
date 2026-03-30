#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = prices[0];
        int max_profit = 0;

        for (int i = 0; i < prices.size() ; i++ )
        {
            if (prices[i] < curr_min)
            {
                curr_min = prices[i];
            } 
            else if (prices[i] - curr_min > max_profit)
            {
                max_profit = prices[i] - curr_min;
            }
        }
    
        return max_profit;
    }
};

auto main() -> int
{
	Solution sol;
    // vector<int> prices{7,1,5,3,6,4};
    vector<int> prices{7,6,4,3,1};

    cout << "profit = " << sol.maxProfit(prices) << endl;
}

