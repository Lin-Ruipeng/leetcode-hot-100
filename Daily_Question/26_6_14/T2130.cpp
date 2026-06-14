// T2130.链表最大孪生和

#include <algorithm>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  int pairSum(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* lastlast = nullptr;
    ListNode* last = nullptr;
    while (fast) {
      fast = fast->next->next;
      last = slow;  // 更新上个
      slow = slow->next;
      last->next = lastlast;  // 反向
      // 更新上和上上个
      lastlast = last;
      last = slow;
    }
    last = lastlast;  // 注意循环最后一次的刷新

    int maxV = last->val + slow->val;
    while (slow && last) {
      maxV = std::max(maxV, last->val + slow->val);
      last = last->next;
      slow = slow->next;
    }
    return maxV;
  }
};

// 思路: 快慢指针找中点,同时前半段反转链表,最后取最大值即可
