// T91.位1的个数

class Solution {
 public:
  int hammingWeight(int n) {
    int sum = 0;
    while (n) {
      sum += (n & 0x1);
      n = n >> 1;
    }
    return sum;
  }
};
