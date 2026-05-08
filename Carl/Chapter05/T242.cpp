// T242 有效的字母异位词

#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    int record[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      record[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); ++i) {
      record[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
      if (record[i]) {
        return false;
      }
    }
    return true;
  }
};
