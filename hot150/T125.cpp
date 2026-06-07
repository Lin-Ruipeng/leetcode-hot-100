// T125.验证回文串

#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
      // 找左侧
      char leftChar;
      while (left < right) {
        if (s[left] <= 'Z' && s[left] >= 'A') {
          leftChar = s[left] - 'A' + 'a';
          break;
        } else if ((s[left] <= 'z' && s[left] >= 'a') ||
                   (s[left] <= '9' && s[left] >= '0')) {
          leftChar = s[left];
          break;
        } else
          ++left;
      }
      // 找右侧
      char rightChar;
      while (left < right) {
        if (s[right] <= 'Z' && s[right] >= 'A') {
          rightChar = s[right] - 'A' + 'a';
          break;
        } else if ((s[right] <= 'z' && s[right] >= 'a') ||
                   (s[right] <= '9' && s[right] >= '0')) {
          rightChar = s[right];
          break;
        } else
          --right;
      }

      // 越界了就不用继续判断了
      if (left >= right) break;

      // 判断本次相同不
      if (leftChar != rightChar) return false;

      ++left;
      --right;
    }

    return true;
  }
};
