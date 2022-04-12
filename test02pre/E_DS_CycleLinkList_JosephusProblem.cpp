//
// DS循环链表—约瑟夫环
//

#include "bits/stdc++.h"

using namespace std;
#define ok 0
#define error -1

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = nullptr;
    }
};

class CLinkList {
public:
    ListNode *head;
    int len;

    CLinkList();

    ~CLinkList();

    ListNode *LL_index(int i); //返回第i个节点的指针，不存在则返回NULL
    void LL_createList(int size);

    int LL_del(int i);

    void LL_Josephus(int k, int s);

    void LL_display();              //输出
};

CLinkList::CLinkList() {
    head = new ListNode;
    len = 0;
}

CLinkList::~CLinkList() {
    delete head;
}

//返回第i个节点的指针，不存在则返回NULL
ListNode *CLinkList::LL_index(int i) {
    int real_pos = i - 1, cnt = -1;
    if (real_pos >= len || real_pos < 0)
        return nullptr;
    ListNode *p = head;
    while (p != nullptr) {
        if (cnt++ != real_pos) {
            p = p->next;
        } else {
            return p;
        }
    }
    return nullptr;
}

void CLinkList::LL_createList(int size) {
    len = size;
    ListNode *p = new ListNode;
    p = head;
    for (int i = 1; i <= len; i++) {
        ListNode *q = new ListNode;
        q->data = i;
        p->next = q;
        p = p->next;
    }
    p->next = head;
}

void CLinkList::LL_display() {
    ListNode *p;
    p = head->next;
    while (p != nullptr) {
        //if (p != head) cout << ' ';
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

int CLinkList::LL_del(int i) {
    int real_pos = i - 1, cnt = 0;
    if (real_pos > len || real_pos < 0)
        return error;
    ListNode *p = head;
    while (p != nullptr) {
        if (cnt++ != real_pos) {
            p = p->next;
        } else {
            ListNode *q = p->next, *r = p->next->next;
            delete q;
            p->next = r;
            len--;
            return ok;
        }
    }
    return error;
}

void CLinkList::LL_Josephus(int k, int s) {
    int cnt = 1, cns = 1, pos = 1;
    ListNode *p = head;
    for (int i = 0; i < s - 1; i++) p = p->next;
    while (len) {
        if (p->next == head) p = p->next;
        for (int i = 0; i < k - 1; i++) {
            p = p->next;
            if (p->next == head) p = p->next;
        }
        ListNode *q = p->next;
        cout << q->data << ' ';
        p->next = q->next;
        delete q;
        len--;
    }
}

int main() {
    int n, k, s;
    while (cin >> n >> k >> s) {
        CLinkList list;
        list.LL_createList(n);
        list.LL_Josephus(k, s);
        cout << endl;
    }
}
