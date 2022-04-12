//
// A. DS顺序表--类实现
//

#include <iostream>

using namespace std;
#define ok 1
#define error -1

class SeqList {
    int *list, maxsize, size;
public:
    //构造函数
    SeqList();

    //含参数的构造函数
    SeqList(int *arr, int n);

    //析构函数，delete功能实现
    ~SeqList();

    //顺序表长度（由于size是私有）
    int list_size();

    //顺序表的插入，i为物理位置（从1开始），item为元素
    int list_insert(int i, int item);

    //顺序表的元素删除
    int list_del(int i);

    //顺序表的元素获取
    int list_get(int i);

    //顺序表的元素打印
    void list_display();
};

SeqList::SeqList() {
    //设定最大长度
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::SeqList(int *arr, int n) {
    //接受一个连续的数组，并赋值给顺序表类中的list数组
    maxsize = 1000;
    size = n;
    list = new int[n];
    list = arr;
}

SeqList::~SeqList() {
    //delete释放内存
    delete[]list;
}

int SeqList::list_size() {
    //返回顺序表大小
    return size;
}

int SeqList::list_insert(int i, int item) {
    /*
     *可以把物理位置转换为逻辑位置，也就是t=i-1，list数组的最大下标为list[size-1]，之后判断以下：
     * 当t>size时，可以认为t的位置超过了数组本来的长度；当t<0，认为t的数组下标为负值，没有意义
     * 从最后一项开始，每次移动一个位置
     */
    if (i > size + 1 || i < 1) {
        cout << "error" << endl;
        return error;
    }
    for (int j = size - 1; j >= i - 1; j--) {
        list[j + 1] = list[j];
    }
    list[i - 1] = item;
    size++;
    return ok;
}

int SeqList::list_del(int i) {
    if (i > size || i < 1) {
        cout << "error" << endl;
        return error;
    }
    for (int j = i - 1; j < size - 1; j++) {
        list[j] = list[j + 1];
    }
    size--;
    return ok;
}

int SeqList::list_get(int i) {
    if (i > size || i < 1) {
        cout << "error" << endl;
        return error;
    }
    cout << list[i - 1] << endl;
    return ok;
}

void SeqList::list_display() {
    cout << size << ' ';
    for (int i = 0; i < size; i++)
        cout << list[i] << ' ';
    cout << endl;
}

int main() {
    int n, item;
    cin >> n;
    SeqList sqlist;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        sqlist.list_insert(i + 1, element);
    }
    sqlist.list_display();

    cin >> n >> item;
    if (sqlist.list_insert(n, item) == ok)
        sqlist.list_display();
    cin >> n >> item;
    if (sqlist.list_insert(n, item) == ok)
        sqlist.list_display();

    cin >> n;
    if (sqlist.list_del(n) == ok)
        sqlist.list_display();
    cin >> n;
    if (sqlist.list_del(n) == ok)
        sqlist.list_display();

    cin >> n;
    sqlist.list_get(n);
    cin >> n;
    sqlist.list_get(n);

    return 0;
}