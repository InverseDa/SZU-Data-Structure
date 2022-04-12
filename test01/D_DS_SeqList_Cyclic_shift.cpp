//
//D. DS顺序表之循环移位
//

#include <iostream>

using namespace std;
#define ok 1
#define error -1

class SeqList {
    int *list, maxsize, size;
public:
    SeqList();

    SeqList(int n, int *item);

    ~SeqList();

    int list_size();

    int list_move(int mode, int n);

    void list_display();
};

SeqList::SeqList() {
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::SeqList(int n, int *item) {
    size = n;
    list = new int[n];
    list = item;
}

SeqList::~SeqList() {
    delete[]list;
}

int SeqList::list_size() {
    return size;
}

int SeqList::list_move(int mode, int n) {
    if (mode) {
        for (int i = 0; i < n; i++) {
            for (int j = size - 1; j >= 0; j--) {
                list[j + 1] = list[j];
            }
            list[0] = list[size];
        }
    } else {
        for (int i = 0; i < size - n; i++) {
            for (int j = size - 1; j >= 0; j--) {
                list[j + 1] = list[j];
            }
            list[0] = list[size];
        }
    }
}

void SeqList::list_display() {
    for (int i = 0; i < size; i++)
        cout << list[i] << ' ';
    cout << endl;
}

int main() {
    int n, item, mode;
    cin >> n;
    int *element = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> element[i];
    }
    SeqList sqlist(n, element);
    sqlist.list_display();
    cin >> mode >> n;
    sqlist.list_move(mode, n);
    sqlist.list_display();
    cin >> mode >> n;
    sqlist.list_move(mode, n);
    sqlist.list_display();

    return 0;
}