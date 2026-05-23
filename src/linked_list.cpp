#include <iostream>
using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ========== 1. 反转链表 ==========
// 核心：三个指针，prev/curr/next 一步步往后挪
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;  // 先保存下一个
        curr->next = prev;             // 反转指向
        prev = curr;                   // prev 前进
        curr = next;                   // curr 前进
    }
    return prev;  // prev 就是新头节点
}

// ========== 2. 合并两个有序链表 ==========
// 核心：比较两个链表的头，小的接到结果后面
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);  // 哑节点，方便操作
    ListNode* tail = &dummy;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    // 把剩余的直接接上
    tail->next = (list1 != nullptr) ? list1 : list2;
    return dummy.next;
}

// ========== 辅助函数：打印链表 ==========
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ========== 辅助函数：创建链表 ==========
ListNode* createList(initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    // 测试反转链表
    ListNode* list1 = createList({1, 2, 3, 4, 5});
    cout << "原链表: ";
    printList(list1);
    ListNode* reversed = reverseList(list1);
    cout << "反转后: ";
    printList(reversed);
    
    // 测试合并两个有序链表
    ListNode* l1 = createList({1, 3, 5});
    ListNode* l2 = createList({2, 4, 6});
    cout << "l1: ";
    printList(l1);
    cout << "l2: ";
    printList(l2);
    ListNode* merged = mergeTwoLists(l1, l2);
    cout << "合并后: ";
    printList(merged);
    
    return 0;
}
