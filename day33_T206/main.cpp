#include <stack>
using namespace std;

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
    ListNode *reverseList(ListNode *head)
    {

        if (head == nullptr)
        {
            return nullptr;
        }

        stack<ListNode *> next_list;
        // 1. 压栈
        while (head != nullptr)
        {
            next_list.push(head);
            head = head->next;
        }

        // 2. 弹出
        head = next_list.top();
        ListNode *old_head = head;
        next_list.pop();
        while (!next_list.empty())
        {
            head->next = next_list.top();
            next_list.pop();
            head = head->next;
        }
        head->next = nullptr;
        return old_head;
    }
};
