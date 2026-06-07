// T58.最后一个单词的长度
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int index = s.size() - 1;
    if (index == -1)
      return 0;
    else if (index == 0) {
      if (s[0] == ' ')
        return 0;
      else
        return 1;
    }

    int length = 0;

    while (s[index] == ' ') {
      --index;
    }
    length = index;
    while (index >= 0 && s[index] != ' ') {
      --index;
    }

    return length - index;
  }
};
