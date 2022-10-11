//
// C. DS顺序表--合并操作
//

#include <iostream>
#include <algorithm>

using namespace std;
#define ok 1
#define error -1

class SeqList {
    int *list, maxsize, size;
public:
    SeqList();

    SeqList(int *arr, int *brr, int n, int m);

    ~SeqList();

    int list_size();

    void list_display();
};

SeqList::SeqList() {
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}


SeqList::SeqList(int *arr, int *brr, int n, int m) {
    size = m + n;
    list = new int[size];
    for (int i = 0; i < n; i++) {
        list[i] = arr[i];
    }
    for (int i = n, k = 0; k < m; i++, k++) {
        list[i] = brr[k];
    }
    sort(list, list + size);
}

SeqList::~SeqList() {
    delete[]list;
}

int SeqList::list_size() {
    return size;
}

void SeqList::list_display() {
    cout << size << ' ';
    for (int i = 0; i < size; i++)
        cout << list[i] << ' ';
    cout << endl;
}

int main() {
    int m, n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    int *brr = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }
    SeqList list3(arr, brr, n, m);
    list3.list_display();

    return 0;
}