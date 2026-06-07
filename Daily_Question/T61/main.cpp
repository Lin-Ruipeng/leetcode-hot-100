// T61.旋转链表

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return nullptr;

    int listSize = 0;
    ListNode* pre = nullptr;  // 前一个节点
    ListNode* cur = head;     // 当前访问节点
    while (cur) {
      pre = cur;
      cur = cur->next;
      ++listSize;
    }
    // 连成环
    pre->next = head;

    // 找偏移量, 切开就行
    int bias = listSize - k % listSize;

    cur = head;
    while (bias--) {
      pre = cur;
      cur = cur->next;
    }
    // 切开
    pre->next = nullptr;

    return cur;
  }
};
