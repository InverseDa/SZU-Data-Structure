//
// Created by inver on 2021/9/22.
//


#include <iostream>
#include <string>
#include <cmath>

using namespace std;
#define ok 0
#define error -1
#define nullptr NULL

class ListNode {
public:
    int val;
    int exp;
    ListNode* next;

    ListNode() {
        next = nullptr;
    }
};

class LinkList {
public:
    ListNode* head;
    int len;

    LinkList();

    ~LinkList();

    int LL_insert(int i, int val, int exp); //在第i的位置插入新节点
    int LL_del(int i);              //删除第i个节点
    void LL_add(LinkList &La) const;
    void LL_display() const;              //输出
};

LinkList::LinkList() {
    head = new ListNode;
    len = 0;
}

LinkList::~LinkList() {
    ListNode* p, * q;
    p = head;
    while (p != nullptr) {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = nullptr;
}

int LinkList::LL_insert(int i, int val, int exp) {
    int real_pos = i - 1, cnt = 0;
    ListNode* p;
    p = head;
    if (real_pos > len || real_pos < 0)
        return error;
    while (p != nullptr) {
        if (cnt++ != real_pos) {
            p = p->next;
        }
        else {
            ListNode* q = new ListNode();
            q->next = p->next;
            p->next = q;
            q->val = val;
            q->exp = exp;
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
    ListNode* p = head;
    while (p != nullptr) {
        if (cnt++ != real_pos) {
            p = p->next;
        }
        else {
            ListNode* q = p->next, * r = p->next->next;
            delete q;
            p->next = r;
            len--;
            return ok;
        }
    }
    return error;
}

void LinkList::LL_add(LinkList &Lb) const {
    ListNode* p, * q;
    p = head->next;
    q = Lb.head->next;
    LinkList afterAddedList;
    ListNode* r = afterAddedList.head;
    while (p && q) {
        if (p->exp < q->exp) {
            r->next = new ListNode;
            r = r->next;
            r->exp = p->exp;
            r->val = p->val;
            p = p->next;
            afterAddedList.len++;
        }
        else if (p->exp > q->exp) {
            r->next = new ListNode;
            r = r->next;
            r->exp = q->exp;
            r->val = q->val;
            q = q->next;
            afterAddedList.len++;
        }
        else {
            if (p->val + q->val == 0) {
                p = p->next;
                q = q->next;
                continue;
            }
            r->next = new ListNode;
            r = r->next;
            r->exp = q->exp;
            r->val = p->val + q->val;
            p = p->next;
            q = q->next;
            afterAddedList.len++;
        }
    }
    while (p) {
        r->next = new ListNode;
        r = r->next;
        r->exp = p->exp;
        r->val = p->val;
        p = p->next;
        afterAddedList.len++;
    }
    while (q) {
        r->next = new ListNode;
        r = r->next;
        r->exp = q->exp;
        r->val = q->val;
        q = q->next;
        afterAddedList.len++;
    }
    r->next = nullptr;
    afterAddedList.LL_display();
}

void LinkList::LL_display() const {
    ListNode* p = head->next;
    for (int i = 0; i < len; i++) {
        if (p->val == 0) {
            p = p->next;
            continue;
        }
        printf("%s%s%d%s", p->val < 0 ? "(" : "", p->val < 0 ? "-" : "", abs(p->val), p->val < 0 ? ")" : "");//如果是负数，则输出（）
        printf("%s%s", p->exp == 0 ? "" : "x", p->exp != 0 ? "^" : "");
        if (p->exp != 0) printf("%s%s%d%s", p->exp < 0 ? "(" : "", p->exp < 0 ? "-" : "", abs(p->exp), p->exp < 0 ? ")" : "");

        if (i != len - 1) printf(" + ");
        p = p->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a;
        LinkList La, Lb;
        for (int i = 1; i <= a; i++) {
            int val, exp;
            cin >> val >> exp;
            La.LL_insert(i, val, exp);
        }
        La.LL_display();
        cin >> b;
        for (int i = 1; i <= b; i++) {
            int val, exp;
            cin >> val >> exp;
            Lb.LL_insert(i, val, exp);
        }
        Lb.LL_display();
        La.LL_add(Lb);
    }
    return 0;
}