// T190.颠倒二进制位

class Solution {
 public:
  int reverseBits(int n) {
    int result = 0;

    for (int i = 0; i < 32; ++i) {
      result = result << 1;
      if (n & (1 << i)) result = result | 1;
    }

    return result;
  }
};
