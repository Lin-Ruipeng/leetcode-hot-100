// T454 四数之和

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> umap;  // a+b的值:出现次数
    // 穷举出a+b，将问题化简为三数之和
    for (auto a : nums1) {
      for (auto b : nums2) {
        umap[a + b]++;
      }
    }
    int count = 0;
    // 穷举出c+d，将问题化简为两数之和
    for (auto c : nums3) {
      for (auto d : nums4) {
        // 两数之和就是直接查表看相反数是否存在
        if (umap.find(0 - c - d) != umap.end()) {
          count += umap[0 - c - d];
        }
      }
    }
    return count;
  }
};
