#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len_A = 0;
        int len_B = 0;

        ListNode *p_A = headA;
        ListNode *p_B = headB;

        // 1. 统计长度
        while (p_A != NULL)
        {
            p_A = p_A->next;
            len_A++;
        }

        while (p_B != NULL)
        {
            p_B = p_B->next;
            len_B++;
        }

        // 2. 长度匹配
        p_A = headA;
        p_B = headB;

        if (len_A > len_B)
        {
            for (int i = 0; i < len_A - len_B; i++)
            {
                p_A = p_A->next;
            }
        }
        else if (len_B > len_A)
        {
            for (int i = 0; i < len_B - len_A; i++)
            {
                p_B = p_B->next;
            }
        }

        // 3. 找相交节点
        while (p_A != NULL)
        {
            if (p_A == p_B)
            {
                return p_A;
            }
            else
            {
                p_A = p_A->next;
                p_B = p_B->next;
            }
        }

        // 4. 没找到
        return NULL;
    }
};
