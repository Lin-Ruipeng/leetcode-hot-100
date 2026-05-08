// T206. 反转链表

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Soultion {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* temp;  // 保存cur的下一个节点
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur) {
      // 先保存后一个节点, 然后修改本节点的指向到前一个节点
      temp = cur->next;
      cur->next = pre;  // 反转链表指向了!
      // 更新 '当前' 和 '上一' 指针
      pre = cur;
      cur = temp;
    }
    return pre;
  }
};
