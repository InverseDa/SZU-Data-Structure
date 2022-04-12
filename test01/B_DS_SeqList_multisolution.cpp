//
// B. DS顺序表--连续操作
//

#include <iostream>

using namespace std;
#define ok 1
#define error -1

class SeqList {
    int *list, maxsize, size;
public:
    SeqList();

    SeqList(int *item, int n);

    ~SeqList();

    int multiinsert(int i, int n, int item[]);

    int multidel(int i, int n);

    void list_display();
};

SeqList::SeqList() {
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::SeqList(int *item, int n) {
    size = n;
    list = new int[n];
    list = item;
}

SeqList::~SeqList() {
    delete[]list;
}

int SeqList::multiinsert(int i, int n, int item[]) {
    int k = 0;
    for (int j = size; j >= i - 1; j--) {
        list[j + n] = list[j];
    }
    for (int j = i - 1; j < i + n - 1; j++) {
        list[j] = item[k++];
    }
    size += n;
    return ok;
}

int SeqList::multidel(int i, int n) {
    for (int j = i - 1; j <= size; j++) {
        list[j] = list[j + n];
    }
    size -= n;
    return ok;
}

void SeqList::list_display() {
    cout << size << ' ';
    for (int i = 0; i < size; i++)
        cout << list[i] << ' ';
    cout << endl;
}

int main() {
    int n, pos;
    cin >> n;
    int *element = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> element[i];
    }
    SeqList sqlist(element, n);
    sqlist.list_display();
    cin >> pos >> n;
    int *item = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> item[i];
    }
    sqlist.multiinsert(pos, n, item);
    sqlist.list_display();

    cin >> pos >> n;
    sqlist.multidel(pos, n);
    sqlist.list_display();


    return 0;
}