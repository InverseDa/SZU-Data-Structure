//
// Created by inver on 2021/12/19.
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

//直接插入排序
void StraightInsertionSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        //tmp为基准值，从i-1逐个比较，如果与基准值相比大，那么就是无序的，就得排序
        int tmp = arr[i], j = 0;
        for (j = i - 1; j >= 0; j--) {
            //如果与基准值相比大，所有元素向后移动
            if (arr[j] > tmp)
                arr[j + 1] = arr[j];
            //否则就跳出
            else break;
        }
        //最后把j+1处的值等于基准值，完成这一轮的排序
        //为什么不是j？这是因为上轮循环之后，j为原来的-1；比如最后j进行到0了，但因为循环的递减，所以实际上j=-1。所以用j+1.
        arr[j + 1] = tmp;
        print(arr, len);
    }

}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    StraightInsertionSort(arr, n);
    cout << endl;
}

