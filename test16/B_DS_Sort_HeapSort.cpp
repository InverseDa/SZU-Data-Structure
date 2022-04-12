//
// Created by inver on 2021/12/22.
//

#include <iostream>

using namespace std;

void print(int *&arr, int len) {
    cout << len << " ";
    for (int i = 0; i < len; i++) {
        if (i != 0)cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

int HeapAdjust(int *&arr, int parent, int len) {
    int temp = arr[parent], child = 2 * parent + 1;
    //有左孩子
    while (child < len) {
        //有右孩子，且值比左孩子还要小，那么就选择右孩子交换
        if (child + 1 < len && arr[child] > arr[child + 1])
            child++;
        //如果孩子的值本身就比双亲小，那么就不交换了
        if (temp <= arr[child]) break;
        //孩子的值给双亲
        arr[parent] = arr[child];
        //选择孩子结点作为双亲，然后孩子选择孩子的左孩子。继续往下筛选
        parent = child;
        child = 2 * child + 1;
    }
    arr[parent] = temp;
}

int HeapSort(int *&arr, int len) {
    //创建初始的小顶堆
    for (int i = len / 2; i >= 0; i--)
        HeapAdjust(arr, i, len);
    print(arr, len);
    //每次交换0和i结点的值，然后在0~i中重新构建小顶堆
    for (int i = len - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        HeapAdjust(arr, 0, i);
        print(arr, len);
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    HeapSort(arr, n);
}