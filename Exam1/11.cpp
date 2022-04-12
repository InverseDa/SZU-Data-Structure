//
// Created by inver on 2021/12/24.
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next, *prior;
};

class List {
public:
    Node *head = new Node;
    int size = 0;

    List() {
        head->next = nullptr;
        head->prior = nullptr;
    }

    void add(int val) {
        Node *p = head, *q = head;
        int cnt = -1;
        while (p) {
            p = p->next;
            if (cnt++ > -1) q = q->next;
        }
        p = new Node;
        p->data = val;
        p->prior = q;
        p->next = nullptr;
        q->next = p;
        size++;
    }

    void find(int val) {
        Node *q = head;
        int cnt = 0;
        while (q) {
            q = q->next;
            if (q->data == val) break;
            cnt++;
        }
        if (cnt == 0) {
            cout << q->next->data << endl;
            return;
        }
        if (q->prior && !q->next) cout << q->prior->data << endl;
        if (!q->prior && q->next) cout << q->next->data << endl;
        if (q->prior && q->next) cout << q->prior->data << " " << q->next->data << endl;
    }
};

int main() {
    int n, t, val;
    List list;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        list.add(val);
    }
    while (t--) {
        int val;
        cin >> val;
        list.find(val);
    }

}