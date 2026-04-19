// T203. 移除链表元素(按照值来移除)

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummyHead(0, head);  // 虚拟头节点
    ListNode* cur = &dummyHead;
    while (cur->next != nullptr) {
      if (cur->next->val == val) {
        auto ptemp = cur->next;
        cur->next = cur->next->next;
        delete ptemp;
      } else {
        cur = cur->next;
      }
    }
    head = dummyHead.next;  // 这个别忘了更新!
    return head;
  }
};