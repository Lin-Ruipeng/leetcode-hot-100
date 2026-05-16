// T42.接雨水 单调栈法

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() <= 2) return 0;
    stack<int> st;  // 存下标
    st.push(0);
    int sum = 0;
    for (int i = 1; i < height.size(); ++i) {
      if (height[i] < height[st.top()]) {
        st.push(i);  // 情况1
      } else if (height[i] == height[st.top()]) {
        st.pop();  // 情况2
        st.push(i);
      } else {
        // 情况3
        while (!st.empty() && height[i] > height[st.top()]) {
          int mid = st.top();
          st.pop();
          if (!st.empty()) {
            int h = min(height[st.top()], height[i]) - height[mid];
            int w = i - st.top() - 1;
            sum += h * w;
          }
        }
        st.push(i);
      }
    }
    return sum;
  }
};
