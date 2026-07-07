// T134.加油站

#include <vector>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
      curSum += gas[i] - cost[i];
      totalSum += gas[i] - cost[i];
      // 如果这个区间和为负数，说明这一段路都是更加耗油的
      // 那么就不要在这个区间里出发
      if (curSum < 0) {
        start = i + 1;
        curSum = 0;
      }
    }
    if (totalSum < 0) return -1;
    return start;
  }
};
