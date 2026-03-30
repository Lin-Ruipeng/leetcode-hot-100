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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 1. 假的头节点
        ListNode dummy;
        ListNode *pdummy = &dummy;

        // 2. 迭代插入
        while (true)
        {
            if (list1 != nullptr && list2 != nullptr)
            {
                if (list1->val <= list2->val)
                {
                    pdummy->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    pdummy->next = list2;
                    list2 = list2->next;
                }
            }
            else if (list1 != nullptr)
            {
                pdummy->next = list1;
                list1 = list1->next;
            }
            else if (list2 != nullptr)
            {
                pdummy->next = list2;
                list2 = list2->next;
            }
            else
            {
                return dummy.next;
            }
            pdummy = pdummy->next;
        }
        return nullptr;
    }
};
