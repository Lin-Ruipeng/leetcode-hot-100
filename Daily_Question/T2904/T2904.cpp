// T2904. 最短且字典序最小的美丽子字符串
// 260826 每日一题

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string shortestBeautifulSubstring(string s, int k) {
    // step 1. Keep track of all 1 subscripts
    vector<int> oneIndex;
    for (int index = 0; index < s.size(); ++index) {
      if (s[index] == '1') {
        oneIndex.push_back(index);
      }
    }
    // step 2. Handle simple cases
    if (oneIndex.size() < k) {
      return "";
    } else if (oneIndex.size() == k) {
      return s.substr(oneIndex[0],
                      1 + oneIndex[oneIndex.size() - 1] - oneIndex[0]);
      // 需要掐头去尾的0
    }
    // step 3. Multiple Windows

    // 先找出所有的子序列
    // <begin index, length> BeautifulSubstring
    vector<int> beginList, lengthList;
    // 一定是这么多个窗口
    for (int i = 0; i <= oneIndex.size() - k; ++i) {
      beginList.push_back(oneIndex[i]);
      lengthList.push_back(oneIndex[i + k - 1] - oneIndex[i] + 1);
    }
    // 最小长度
    int minLenth = lengthList[0];
    for (int i = 1; i <= oneIndex.size() - k; ++i) {
      if (lengthList[i] < minLenth) {
        minLenth = lengthList[i];
      }
    }
    // 最后收集所有最短序列并根据字典序排序
    vector<string> allSubstring;
    for (int i = 0; i <= oneIndex.size() - k; ++i) {
      if (lengthList[i] == minLenth) {
        allSubstring.push_back(s.substr(beginList[i], lengthList[i]));
      }
    }
    sort(allSubstring.begin(), allSubstring.end());
    return allSubstring[0];
  }
};
