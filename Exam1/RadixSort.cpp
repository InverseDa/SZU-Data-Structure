//
// Created by inver on 2021/12/24.
//

#include <bits/stdc++.h>

using namespace std;


void print(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int getMaxBit(vector<int> arr) {
    int max = 0;
    for (int i = 0; i < arr.size(); i++)
        if (max < arr[i]) max = arr[i];
    int p = 0;
    while (max != 0) {
        max = max / 10;
        p++;
    }
    return p;
}

void RadixSort(vector<int> &arr) {
    int d = getMaxBit(arr);
    int radix = 1;
    vector<int> temp(arr);
    vector<queue<int>> q(10);
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < arr.size(); j++) {
            int p = (arr[j] / radix) % 10;
            q[p].push(arr[j]);
        }
        int pos = 0;
        for (int i = 0; i < 10; i++) {
            while (!q[i].empty()) {
                temp[pos++] = q[i].front();
                q[i].pop();
            }
        }
        radix *= 10;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        RadixSort(arr);
        print(arr);
        cout << endl;
    }
}