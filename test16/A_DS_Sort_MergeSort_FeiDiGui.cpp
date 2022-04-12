//
// Created by inver on 2021/12/22.
//

#include <iostream>

using namespace std;

void print(string *arr, int len) {
    for (int i = 0; i < len; i++) {
        if (i != 0)cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

//非递归实现归并排序
void MergeSort(string arr[], int len) {
    //创建临时数组
    string *temp = new string[len];
    //生成归并排序所需要的长度。
    int k = 1;
    while (k < len) k *= 2;
    //进行归并
    for (int i = 2; i < k + 1; i *= 2) {
        //思想是，先分解到最小单元，逐个排序合并
        for (int j = 0; j < len; j += i) {
            //第一次是0，1；第二次1，1...直到n,n
            //然后第二趟第一次就是0，2；第二次2，4.。。所以看得出，这确实是分解出最小单元，然后逐个合并
            int left = j, right = j + i / 2, mid = right - 1, v = left;
            if (right > len) break;
            //合并过程
            while (left <= mid && right < len && right < i + j) {
                if (arr[left] > arr[right]) temp[v++] = arr[left++];
                else temp[v++] = arr[right++];
            }
            while (left <= mid) temp[v++] = arr[left++];
            while (right < len && right < i + j) temp[v++] = arr[right++];
            //最后赋值给原数组
            for (int p = j; p < j + i && p < len; p++) {
                arr[p] = temp[p];
            }
        }
        print(arr, len);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string *arr = new string[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        MergeSort(arr, n);
        cout << endl;
    }
}