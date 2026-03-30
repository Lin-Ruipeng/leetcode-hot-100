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
    ListNode *swapPairs(ListNode *head)
    {
        // 1. 先处理两个节点都没有的情况
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // 2. 虚拟头节点和三个指针
        ListNode dummyHead(0, head);
        ListNode *prev = &dummyHead; // 前驱节点
        ListNode *curr = head;       // 当前节点

        while (curr != nullptr && curr->next != nullptr)
        {
            // 交换 (temp是节点2,curr是节点1,prev是节点0)
            ListNode *temp = curr->next; // 临时节点记录下一位置
            // 三行交换  源头:[prev -> 1 -> 2 -> 3] 目标:[prev -> 2 -> 1 -> 3]
            prev->next = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            // 交换完成之后更新指针,curr指向3,prev指向1
            prev = curr;
            curr = curr->next;
        }

        return dummyHead.next;
    }
};

/*
 * 三行交换原理解释:
 * prev同名 1是curr 2是temp
 *
 * prev -> 1 -> 2 -> 3 源
 * prev -> 2 -> 1 -> 3 目标
 *
 * prev->next(1) = 1->next(2)
 * p -> 2 -> 3
 * 1 -> 2
 *
 * 1->next(2) = 2->next(3)
 * p -> 2 -> 3
 *      1 -> 3
 *
 * 2->next = 1
 * p -> 2 -> 1 -> 3
 *
 * 交换完成更新的解释
 * 源头: temp是节点2,curr是节点1,prev是节点0
 * 目标: curr是3,prev是1
 *  prev(0) = curr(1)
 *  curr(1) = curr->next(3)
 */