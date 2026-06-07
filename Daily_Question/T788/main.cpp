// T788.旋转数字

#include <unordered_set>

using namespace std;

class Solution {
 public:
  int rotatedDigits(int n) {
    int count = 0;

    unordered_set<int> rotateSet = {0, 1, 8, 2, 5, 6, 9};
    unordered_set<int> changeSet = {2, 5, 6, 9};

    for (int i = 0; i <= n; ++i) {
      // 对i进行判定
      bool changed = false;
      int temp = i;
      while (temp) {
        // 对每一位进行判定
        int mod = temp % 10;
        temp /= 10;
        if (rotateSet.find(mod) != rotateSet.end()) {
          if (changeSet.find(mod) != changeSet.end()) {
            changed = true;
          }
        } else {
          changed = false;
          break;
        }
      }
      if (changed) ++count;
    }

    return count;
  }
};
