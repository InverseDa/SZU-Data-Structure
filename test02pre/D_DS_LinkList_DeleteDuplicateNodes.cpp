//
// DS单链表—删除重复元素
//

#include <iostream>

using namespace std;
#define ok 0
#define error -1
#define nullptr NULL

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
    int LL_deleteDuplicateElem();

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
    ListNode *p, *q;
    p = head;
    while (p != nullptr) {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
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

int LinkList::LL_deleteDuplicateElem() {
    ListNode *p = head->next, *q = head;
    int hashmap[100000] = {0};
    int fuhash[100000] = {0};
    while (p != nullptr) {
        if (p->data < 0) {
            if (++fuhash[-1 * p->data] > 1) {
                ListNode *rub = p;
                q->next = p->next;
                len--;
            } else q = p;
        } else {
            if (++hashmap[p->data] > 1) {
                ListNode *rub = p;
                q->next = p->next;
                len--;
            } else q = p;
        }
        p = p->next;
    }
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
        cout << ' ' << p->data;
        p = p->next;
    }
    cout << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int size;
        cin >> size;
        LinkList list;
        for (int i = 1; i <= size; i++) {
            int val;
            cin >> val;
            list.LL_insert(i, val);
        }
        list.LL_deleteDuplicateElem();
        cout << list.len << ":";
        list.LL_display();
    }
    return 0;
}