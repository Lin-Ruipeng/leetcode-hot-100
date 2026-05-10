// T707.设计链表
#include <iostream>

class MyLinkedList {
 public:
  // 链表节点结构体
  struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val), next(nullptr) {}
  };

  // 初始化链表(构造函数)
  MyLinkedList() {
    // 引入虚拟头节点, 方便管理
    _dummyHead = new LinkedNode(0);
    _size = 0;
  }
  MyLinkedList() { delete _dummyHead; }

  // 获取第i个节点的数值
  int get(int index) {
    // 千万要注意到size_t要避免 0-1
    if (index < 0 || index + 1 > _size) {
      return -1;  // -1 表示非法
    }
    LinkedNode* cur = _dummyHead->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  // 头插
  void addAtHead(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    newNode->next = _dummyHead->next;
    _dummyHead->next = newNode;
    ++_size;
  }

  // 尾插
  void addAtTail(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = _dummyHead;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = newNode;
    ++_size;
  }

  // 中间插入
  void addAtIndex(int index, int val) {
    if (index > _size) {
      return;
    }
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    ++_size;
  }

  // 删除index下标节点
  void deleteAtIndex(int index) {
    if (index >= _size || index < 0) {
      return;
    }
    LinkedNode* cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    LinkedNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    --_size;
  }

  void printLinkedList() {
    LinkedNode* cur = _dummyHead;
    while (cur->next != nullptr) {
      std::cout << cur->next->val << " ";
      cur = cur->next;
    }
    std::cout << std::endl;
  }

 private:
  LinkedNode* _dummyHead;
  std::size_t _size;
};
