//
// Created by inver on 2021/12/23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//输出数组
void print(vector<int> arr, int len) {
    for (int i = 0; i < len; i++) {
        if (i != 0)cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

//获取最大的位数
int getMaxBit(vector<int> arr, int len) {
    int max = arr[0];
    for (int i = 0; i < len; i++) {
        if (arr[i] > max) max = arr[i];
    }
    int d = 1, p = 10;
    while (max >= p) {
        max /= 10;
        d++;
    }
    return d;
}

//队列的输出（按格式）
void printQueue(vector<queue<int>> myQueue) {
    for (int i = 0; i < 10; i++) {
        if (myQueue[i].empty()) cout << i << ":NULL" << endl;
        else {
            cout << i << ":";
            while (!myQueue[i].empty()) {
                cout << "->" << myQueue[i].front();
                myQueue[i].pop();
            }
            cout << "->^" << endl;
        }
    }
}

//判断是否有负数
bool judge(const vector<int> &arr, int &min) {
    for (int i : arr) {
        if (i < min) return true;
    }
    return false;
}

void RadixSort(vector<int> arr, int len) {
    //d为最大位数
    int d = getMaxBit(arr, len);
    //temp为临时数组，myQueue为队列数组
    vector<int> temp(arr);
    vector<queue<int>> myQueue(10);
    //radix为基数
    int radix = 1, k;
    //min为最小值，若judge判断为true，说明数组中存在负数
    int min = 0;
    if (judge(arr, min)) {
        //将所有项加上最小负数，这样所有数都是正数
        min *= -1;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] += min;
        }
        //然后按往常排序就行，不过注意加入队列的时候还是要减回去
        for (int i = 1; i <= d; i++) {
            for (int j = 0; j < len; j++) {
                k = (arr[j] / radix) % 10;
                myQueue[k].push(arr[j] - min);
            }
            int pos = 0;
            //打印队列
            printQueue(myQueue);
            //出队，并且将值给temp数组
            for (int j = 0; j < 10; j++) {
                while (!myQueue[j].empty()) {
                    temp[pos++] = myQueue[j].front();
                    myQueue[j].pop();
                }
            }
            //基数乘以10，下一轮排序用
            radix *= 10;
            //赋值给arr，最后输出arr
            for (int j = 0; j < len; j++)
                arr[j] = temp[j];
            print(arr, len);
        }
    } else {
        //没有负数的处理，基本一致
        for (int i = 1; i <= d; i++) {
            for (int j = 0; j < len; j++) {
                k = (arr[j] / radix) % 10;
                myQueue[k].push(arr[j]);
            }
            int pos = 0;
            printQueue(myQueue);
            for (int j = 0; j < 10; j++) {
                while (!myQueue[j].empty()) {
                    temp[pos++] = myQueue[j].front();
                    myQueue[j].pop();
                }
            }
            radix *= 10;
            for (int j = 0; j < len; j++)
                arr[j] = temp[j];
            print(arr, len);
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
        RadixSort(arr, (int) arr.size());
        cout << endl;
    }
}
