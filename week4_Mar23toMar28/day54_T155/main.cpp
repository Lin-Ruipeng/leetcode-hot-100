#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    int min;
    Node *next;

    // 初始化列表
    Node(int v, int m, Node *n = nullptr) : val(v), min(m), next(n) {}
};

class MinStack
{
private:
    Node *head; // 一直记录头部
public:
    MinStack()
    {
        head = nullptr;
    }

    void push(int val)
    {
        // 头插法来模拟栈
        int currentMin;
        if (head != nullptr)
        {
            // 要么现在值更小,要么前一个最小值更小
            currentMin = min(val, head->min);
        }
        else
        {
            // 没有元素的时候就是当前值最小
            currentMin = val;
        }
        // new一个头 插入
        head = new Node(val, currentMin, head);
    }

    void pop()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->min;
    }
};

auto main() -> int
{
    cout << "Hello World!" << endl;
}
