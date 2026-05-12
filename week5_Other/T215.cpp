// T215. 数组中的第k个最大元素

#include <queue>
#include <vector>

using namespace std;

class Solution {
  class compare {
   public:
    bool operator()(int a, int b) {
      return a > b;  // 小顶堆
    }
  };

 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, compare> pri_que;
    for (auto num : nums) {
      pri_que.push(num);
      if (pri_que.size() > k) {
        pri_que.pop();
      }
    }
    return pri_que.top();
  }
};
