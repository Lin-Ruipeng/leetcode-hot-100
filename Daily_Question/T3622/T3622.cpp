// T3622. 判断整除性

class Solution {
 public:
  bool checkDivisibility(int n) {
    int raw_n = n;
    int product = 1;
    int sum = 0;
    while (n) {
      int bit = n % 10;
      n = n / 10;
      sum += bit;
      product *= bit;
    }
    return !(raw_n % (sum + product));
  }
};
