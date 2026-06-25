// T131.分割回文串

#include <string>
#include <vector>
using namespace std;

class Solution {
  bool isPalindrome(const string& s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

  vector<vector<string>> result;
  vector<string> path;  // 已经回文的子串
  void backtracking(const string& s, int startIndex) {
    // 起始位置大于s说明已经找到一组回文
    if (startIndex >= s.size()) {
      result.push_back(path);
      return;
    }

    for (int i = startIndex; i < s.size(); ++i) {
      if (isPalindrome(s, startIndex, i)) {
        // 是回文
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
      } else {
        // 不是回文就跳过
        continue;
      }
      backtracking(s, i + 1);
      path.pop_back();  // 回溯
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    result.clear();
    path.clear();
    backtracking(s, 0);
    return result;
  }
};
