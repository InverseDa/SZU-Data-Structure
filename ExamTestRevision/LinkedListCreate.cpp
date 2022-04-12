//
// Created by inver on 2021/12/22.
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class LinkedList {
public:
    Node *head = new Node;
    int size = 0;

    void add(int data) {
        Node *p = head->next, *q = head;
        int cnt = 0;
        while (p != nullptr && size != cnt) {
            q = q->next;
            p = p->next;
            cnt++;
        }
        Node *t = new Node;
        q->next = t;
        t->data = data;
        size++;
    }

    void del(int pos) {
        Node *p = head->next, *q = head;
        int cnt = 1;
        while (p != nullptr && cnt != pos) {
            p = p->next;
            q = q->next;
            cnt++;
        }
        q->next = p->next;
        delete p;
        size--;
    }

    void print() {
        Node *p = head->next;
        int cnt = 0;
        while (p && cnt != size) {
            cout << p->data << " ";
            p = p->next;
            cnt++;
        }
        cout << endl;
    }

    int get(int index) {
        Node *p = head->next;
        int cnt = 0;
        while (p && cnt != index) {
            p = p->next;
            cnt++;
        }
        return p->data;
    }

    void merge(LinkedList l1, LinkedList l2) {
        int i = 0, j = 0;
        while (i < l1.size && j < l2.size) {
            if (l1.get(i) < l2.get(j)) {
                this->add(l1.get(i++));
            } else
                this->add(l2.get(j++));
        }
        while (i < l1.size) {
            this->add(l1.get(i++));
        }
        while (j < l2.size) {
            this->add(l2.get(j++));
        }
    }
};

int main() {
    LinkedList l1, l2, l3;
    for (int i = 1; i <= 9; i += 2) {
        l1.add(i);
    }
    for (int i = 2; i <= 10; i += 2) {
        l2.add(i);
    }
    l3.merge(l1, l2);
    l3.print();
}