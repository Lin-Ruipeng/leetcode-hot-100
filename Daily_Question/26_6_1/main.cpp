#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    int sum = 0;
    sort(cost.begin(), cost.end(), std::greater<int>());
    for (size_t i = 0; i < cost.size(); ++i) {
      if ((i + 1) % 3 == 0) {
        continue;
      } else {
        sum += cost[i];
      }
    }
    return sum;
  }
};
