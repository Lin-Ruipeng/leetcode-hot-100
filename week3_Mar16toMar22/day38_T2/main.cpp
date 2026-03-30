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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummyHead;
        ListNode *pdummy = &dummyHead;
        int digit = 0; // 记录进位

        while (l1 != nullptr || l2 != nullptr || digit != 0)
        {
            int sum = digit;

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            digit = sum / 10; // 进位
            sum = sum % 10;   // 取余

            // 存入本次计算结果
            pdummy->next = new ListNode(sum);
            // 更新尾指针
            pdummy = pdummy->next;
        }

        return dummyHead.next;
    }
};