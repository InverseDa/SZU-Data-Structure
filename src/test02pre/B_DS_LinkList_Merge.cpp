//
// DS单链表--合并
//

#include "iostream"

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

class LinkList {
public:
    ListNode *head;
    int len;

    LinkList();

    ~LinkList();

    ListNode *LL_index(int i); //返回第i个节点的指针，不存在则返回NULL
    int LL_merge(LinkList &La, LinkList &Lb, LinkList &Lc);

    int LL_get(int i);              //获取第i个节点
    int LL_insert(int i, int item); //在第i的位置插入新节点
    int LL_del(int i);              //删除第i个节点
    void LL_display();              //输出
};

LinkList::LinkList() {
    head = new ListNode;
    len = 0;
}

LinkList::~LinkList() {
    auto ptr = head;
    ListNode *tmp;
    while (ptr) {
        tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    head = nullptr;
}

//返回第i个节点的指针，不存在则返回NULL
ListNode *LinkList::LL_index(int i) {
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

int LinkList::LL_merge(LinkList &La, LinkList &Lb, LinkList &Lc) {
    ListNode *p, *q, *r;
    p = La.head->next, q = Lb.head->next, Lc.head = r = La.head;
    while (p != nullptr && q != nullptr) {
        if (p->data <= q->data) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    r->next = p ? p : q;
    Lc.len = La.len + Lb.len;
    delete Lb.head;
    return ok;
}

int LinkList::LL_get(int i) {
    int cnt = 0, real_pos = i - 1;
    ListNode *p = head;
    if (real_pos >= len || real_pos < 0)
        return error;
    while (p != nullptr) {
        p = p->next;
        if (cnt++ == real_pos)
            return p->data;
    }
    return error;
}

int LinkList::LL_insert(int i, int item) {
    int real_pos = i - 1, cnt = 0;
    ListNode *p;
    p = head;
    if (real_pos > len || real_pos < 0)
        return error;
    while (p != nullptr) {
        if (cnt++ != real_pos) {
            p = p->next;
        } else {
            ListNode *q = new ListNode();
            q->next = p->next;
            p->next = q;
            q->data = item;
            len++;
            return ok;
        }
    }
    return error;
}

int LinkList::LL_del(int i) {
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

void LinkList::LL_display() {
    ListNode *p;
    p = head->next;
    while (p != nullptr) {
        //if (p != head) cout << ' ';
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;
    LinkList la;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        la.LL_insert(i, val);
    }
    cin >> m;
    LinkList lb;
    for (int i = 1; i <= m; i++) {
        int val;
        cin >> val;
        lb.LL_insert(i, val);
    }
    LinkList lc;
    lc.LL_merge(la, lb, lc);
    lc.LL_display();

    la.head = nullptr;
    lb.head = nullptr;
    return 0;
}