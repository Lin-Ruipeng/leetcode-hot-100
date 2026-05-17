// T151.反转字符串中的单词

#include <string>

using namespace std;

class Solution {
 public:
  void reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      swap(s[i], s[j]);
    }
  }
  // 双指针法删除多余空格
  void removeExtraSpaces(string& s) {
    int slowIndex = 0, fastIndex = 0;
    while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
      ++fastIndex;
    }
    for (; fastIndex < s.size(); ++fastIndex) {
      if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] &&
          s[fastIndex] == ' ') {
        continue;
      } else {
        s[slowIndex++] = s[fastIndex];
      }
    }
    // 去掉末尾的空格
    if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
      s.resize(slowIndex - 1);
    } else {
      s.resize(slowIndex);  // 重新设置字符串大小
    }
  }
  string reverseWords(string s) {
    removeExtraSpaces(s);         // 先删除头尾空格
    reverse(s, 0, s.size() - 1);  // 完全反转
    int start = 0, end = 0;
    bool entry = false;  // 标记是否进入单词区间
    for (int i = 0; i < s.size(); ++i) {
      if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {
        start = i;     // 单词起始位
        entry = true;  // 进入单词区间
      }
      if (entry && s[i] == ' ' && s[i - 1] != ' ') {
        end = i - 1;  // 确定单词终止位
        entry = false;
        reverse(s, start, end);
      }
      // 最后一个单词之后没有空格的情况
      if (entry && (i == (s.size() - 1)) && s[i] != ' ') {
        end = i;
        entry = false;
        reverse(s, start, end);
      }
    }
    return s;
  }
};
