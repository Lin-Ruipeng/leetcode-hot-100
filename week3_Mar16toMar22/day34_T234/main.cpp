
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
    bool isPalindrome(ListNode *head)
    {
        // 1. 先快慢指针找中点
        ListNode *pfast = head;
        ListNode *pslow = head;
        while (pfast->next != nullptr && pfast->next->next != nullptr)
        {
            pfast = pfast->next->next;
            pslow = pslow->next;
        }

        // 2. 再对后半部分反转
        ListNode *pprev = nullptr;     // 前一个
        ListNode *pcurr = pslow->next; // 当前
        ListNode *pnext = nullptr;
        pslow->next = nullptr; // 断开，前半部分独立
        while (pcurr != nullptr)
        {
            pnext = pcurr->next; // 先存下一个
            pcurr->next = pprev; // 反转
            pprev = pcurr;       // prev前移
            pcurr = pnext;       // curr前移
        }

        ListNode *ptail = pprev;
        // 3. 判断回文
        while (ptail != nullptr)
        {
            if (head->val != ptail->val)
            {
                return false;
            }
            head = head->next;
            ptail = ptail->next;
        }

        return true;
    }
};
