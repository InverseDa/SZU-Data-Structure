//
// Created by inver on 2022/3/7.
//

#include <iostream>
#include<Windows.h>

using namespace std;

class MergeSort {
public:
    int array[50000];
    int n;
    int temp[50000];
    long time;

    MergeSort(int n1) {
        n = n1;
        for (int i = 0; i < n; i++) {
            array[i] = rand() % n; //随机赋值给数组
            temp[i] = array[i];
        }
        DWORD startTime = GetTickCount(); //计时开始
        mergesort();
        DWORD endTime = GetTickCount(); //计时结束
        time = endTime - startTime;
        print();
    }

    void mergesort() {
        /*int gap = 1;
        int i;
        int j;
        while (gap < n) {
            i = 0;
            j = i + gap;
            while (j < n) {
                Merge(i, j, gap);
                i += gap * 2;//每次跳两个组的间距
                j += gap * 2;
            }
            gap = gap * 2;
        }
        */
        //创建临时数组
        int *temp = new int[n];
        //生成归并排序所需要的长度。
        int k = 1;
        while (k < n) k *= 2;
        //进行归并
        for (int i = 2; i < k + 1; i *= 2) {
            //思想是，先分解到最小单元，逐个排序合并
            for (int j = 0; j < n; j += i) {
                //第一次是0，1；第二次1，1...直到n,n
                //然后第二趟第一次就是0，2；第二次2，4.。。所以看得出，这确实是分解出最小单元，然后逐个合并
                int left = j, right = j + i / 2, mid = right - 1, v = left;
                if (right > n) break;
                //合并过程
                while (left <= mid && right < n && right < i + j) {
                    if (array[left] > array[right]) temp[v++] = array[left++];
                    else temp[v++] = array[right++];
                }
                while (left <= mid) temp[v++] = array[left++];
                while (right < n && right < i + j) temp[v++] = array[right++];
                //最后赋值给原数组
                for (int p = j; p < j + i && p < n; p++) {
                    array[p] = temp[p];
                }
            }
        }
    }

    /*void Merge(int m1, int m2, int gap) {//合并两个区间
        int k = m1;
        int i = m1, j = m2;
        for (i = m1, j = m2, k = m1; i < m1 + gap && j < m2 + gap && j < n; k++) {
            if (array[i] < array[j])
                temp[k] = array[i++];
            else
                temp[k] = array[j++];
        }
        while (i < m1 + gap)
            temp[k++] = array[i++];
        while (j < m2 + gap && j < n)
            temp[k++] = array[j++];
        for (int l = 0; l < n; l++)
            array[l] = temp[l];
    }*/

    void print() {
        /*for (int i = 0; i < n; i++)  //输出部分
        {
            cout << array[i] << " ";
        }*/
        cout << "二路合并排序时间为" << time << "ms" << "\n";
    }
};

int main() {
    int t, SampleNum;
    cout << "请输入样本组数\n";
    cin >> SampleNum;  //样本组数
    t = SampleNum;
    long sumtime = 0;  //分别是各种排序的时间
    int n;
    cout << "请输入n\n";
    cin >> n;//数组大小
    while (t--) {
        MergeSort MSort(n); //选择排序的类
        sumtime += MSort.time;
    }
    cout << "二路合并排序算平均时间为" << sumtime / SampleNum << "ms" << "\n";
    return 0;
}


