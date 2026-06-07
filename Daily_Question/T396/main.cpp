// T396.旋转函数
// 26_05_01每日一题

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int F0 = 0;  // 先求出F1和sum
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      F0 += i * nums[i];
      sum += nums[i];
    }

    // 仔细分析数学公式可以知道
    // F(n) = F(n-1) + sum - nums.size() * nums[-n]
    // 这里的sum就是nums总和

    int maxF = F0;
    int Fn_1 = F0;
    for (size_t i = 1; i < nums.size(); ++i) {
      int Fn = Fn_1 - nums.size() * nums[nums.size() - i] + sum;
      Fn_1 = Fn;             // 更新对上一次结果的记录
      maxF = max(maxF, Fn);  // 更新最大值
    }

    return maxF;
  }
};
