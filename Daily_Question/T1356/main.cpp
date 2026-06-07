// T1356.根据数字二进制下1的数目排序

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      // 一定要复制一份因为后面还要考虑基于原始数据进行大小比较!!!
      // 当1的个数一致的时候就要用到原始数据了!
      int A = a, B = b;
      int ca = 0, cb = 0;
      while (A) {
        ca += A & 1;
        A >>= 1;
      }
      while (B) {
        cb += B & 1;
        B >>= 1;
      }
      if (ca != cb) return ca < cb;
      return a < b;
    });
    return arr;
  }
};
