//
// Created by inver on 2021/12/16.
//

#include <iostream>

using namespace std;
//打印每一趟的数组
void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}
//快速排序，每次取begin对应的数组为基准值
void QuickSort(int *arr, int len, int begin, int end) {
    //如果begin大于等于end，返回
    if (begin >= end) return;
    //基准值和i，j的设置
    int tmp = arr[begin], i = begin, j = end;
    //当i不等于j的时候进行循环
    while (i < j) {
        //j在最右端，找到arr[j]小于基准值的位置
        while (arr[j] >= tmp && j > i)
            j--;
        arr[i] = arr[j];
        //i在最左端，找到arr[i]大于基准值的位置
        while (arr[i] <= tmp && j > i)
            i++;
        arr[j]=arr[i];
    }
    //最后在i=j处与基准值交换
    arr[i] = tmp;

    //打印这一趟排序
    print(arr, len);
    //进行新一轮的排序
    QuickSort(arr, len, begin, i - 1);
    QuickSort(arr, len, i + 1, end);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        //注意end是n-1
        QuickSort(arr, n, 0, n - 1);
        cout << endl;
    }
}


