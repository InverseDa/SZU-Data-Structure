//
// Created by inver on 2021/11/25.
//

#include <iostream>

using namespace std;

//二分查找，折半查找
double binarySearch(int key) {
    //low指针在第一位，high指针在最后一位
    double low = 0, high = key;
    while (low <= high) {
        double mid = (low + high) / 2;
        if (abs(mid * mid - key) <= 1e-5) return mid;
        if (mid * mid >= key) high = mid;
        else low = mid;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int key;
        cin >> key;
        printf("%.3lf\n", binarySearch(key));
    }
}