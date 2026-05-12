// T347. 前k个高频元素
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  // 手动实现的小顶堆
  class mycomparison {
   public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;
    }
  };
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // 1. 先统计各个元素的出现次数
    unordered_map<int, int> map;  // value是出现次数
    for (int i = 0; i < nums.size(); ++i) {
      map[nums[i]]++;
    }
    // 2. 用小顶堆对出现次数进行排序，次数少的就在堆顶部，并且更小的就丢弃
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison>
        pri_que;

    // 用固定大小为k的小顶堆遍历所有的元素出现次数的数值
    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end();
         it++) {
      pri_que.push(*it);
      if (pri_que.size() > k) {
        // 当这个堆的大小大于k，那么就需要弹出最少的元素
        pri_que.pop();
      }
    }
    // 找出前k个高频元素，记得这个是小顶堆，需要倒序输出
    vector<int> result(k);
    for (int i = k - 1; i >= 0; --i) {
      result[i] = pri_que.top().first;
      pri_que.pop();
    }
    return result;
  }
};
