#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummyHead(0, head); // 假头,防止需要修改head的情况
        ListNode *fast = head;       // 快指针
        ListNode *slow = &dummyHead; // 慢指针

        // 1. 快指针先走n步
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // 2. 然后一起走
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // 3. 删除节点
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        temp = nullptr;
        return dummyHead.next;
    }
};
