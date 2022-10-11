//
// Created by inver on 2021/12/16.
//

#include <iostream>

using namespace std;

void BubbleSort(int *arr, int arrLength) {
    int cnt = 0;
    for (int i = 0; i < arrLength - 1; i++) {
        for (int j = 0; j < arrLength - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    int n;
    while (cin >> n) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        BubbleSort(arr, n);
    }
}

