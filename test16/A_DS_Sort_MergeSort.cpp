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

void Merge(string *arr, string *temp, int len, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] >= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    k = 0;
    i = left;
    while (i <= right) {
        arr[i++] = temp[k++];
    }
    print(arr, len);
}

void Sort(string *arr, string *temp, int len, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        Sort(arr, temp, len, left, mid);
        Sort(arr, temp, len, mid + 1, right);
        Merge(arr, temp, len, left, mid, right);
    }
}

void MergeSort(string arr[], int len) {
    string *temp = new string[len];
    Sort(arr, temp, len, 0, len - 1);
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