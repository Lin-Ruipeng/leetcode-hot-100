// T3314.构造最小位运算数组 I
// T3315.构造最小位运算数组 II

// 此代码对这题都有效

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] == 2) continue;
      int position = 0;
      while ((1 << position) & nums[i]) {
        ++position;
      }
      ans[i] = nums[i] & (~(1 << position - 1));
    }
    return ans;
  }
};

/***
 * 思路解释:
 * 首先输入都是质数,那么就只有2是偶数需要分类讨论,
 * 对于输入是2: 初始化为-1专门用于处理2的情况
 * 对于输入不是2: 那么nums[i]转成二进制一定是最后一位是1,
 * 然后考虑到,ans[i] | (ans[i] + 1)
 * 那么就能想到,这种或运算的情况就可以简化为:
 * case 1: 00 | 01 加1不进位
 * case 2: 01 | 10 加1会进位
 * 然后把这两种情况推广一下:
 * case 1: 0110 | 0111 加1不进位,最后末尾或完多了一个1
 * case 2: 0111 | 1000 加1进位,最开头或完多了一个1
 * 那么就可以总结了,就是你或上自己+1就会在二进制表示上多一1
 * 那么简单,你就想怎么让ans[i]和nums[i]在二进制上相比只少一个1,
 * 并且这个1可以用 | ans[i] + 1 来补齐
 * 那么你再考虑到,输入都是奇数,所以都是以1为结尾,
 * 那你肯定就是想到,好好利用case2就好(补充case2就是最后几位全是1)
 * 比如说,随便举个例子, nums[i] = 1010 1111
 * 那么就很显然,倒数的第四个1是最后一个从尾巴往前数的1
 * 那么你就会想到 ans[i] = 1010 0111 (只改动1位)
 * 然后就会有 ans[i]+1 = 1010 1000
 * 或完正好就是答案!
 */
