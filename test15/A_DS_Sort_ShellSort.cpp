//
// Created by inver on 2021/12/16.
//

#include <iostream>

using namespace std;

void ShellSort(int *arr, int arrLength) {
    int j;
    //分组，每次除以二
    for (int gap = arrLength / 2; gap > 0; gap /= 2) {
        //从gap开始
        for (int i = gap; i < arrLength; i++) {
            int insert = arr[i];
            //如果后面大于前面，交换
            for (j = i; j >= gap && insert > arr[j - gap]; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = insert;
        }
        //遍历每次排序的结果
        for (int k = 0; k < arrLength; k++) {
            if (k != 0) cout << " ";
            cout << arr[k];
        }
        cout << endl;
    }
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
        ShellSort(arr, n);
        cout << endl;
    }
}

