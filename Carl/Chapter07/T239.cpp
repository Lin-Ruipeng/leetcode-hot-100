// T239.滑动窗口内最大值

#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  class MyQueue {  // 单调队列(降序)
   public:
    deque<int> que;  // deque来实现
    void pop(int value) {
      // 只会将滑动窗口尾巴的数字弹出,也就是出范围弹出
      if (!que.empty() && value == que.front()) {
        que.pop_front();
      }
    }
    void push(int value) {
      // 都比滑动窗口头部新进入的数字小就可以弹出了
      while (!que.empty() && value > que.back()) {
        que.pop_back();
      }
      que.push_back(value);
    }
    int front() { return que.front(); }
  };

 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MyQueue que;
    vector<int> result;
    // 首先达到窗口长度k
    for (int i = 0; i < k; ++i) {
      que.push(nums[i]);
    }
    // 然后开始记录最大值
    result.push_back(que.front());
    for (int i = k; i < nums.size(); ++i) {
      que.pop(nums[i - k]);           // 先移除窗口尾元素
      que.push(nums[i]);              // 加入窗口头部元素
      result.push_back(que.front());  // 队头一定是最大元素
    }
    return result;
  }
};
