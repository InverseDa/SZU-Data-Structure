//
// C. DS串应用—最长重复子串
//
// 利用后缀数组解决

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringLenFinder(string s1, string s2) {
    int i = 0;
    while (i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
        i++;
    }
    return i;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        vector<string> pat;
        int max = -1, len = 0;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
            pat.push_back(str.substr(i));
        sort(pat.begin(), pat.end());
        for (int i = 1; i < pat.size(); i++) {
            len = stringLenFinder(pat[i - 1], pat[i]);
            if (len > max && len <= str.size() / 2) max = len;
        }
        printf("%d\n", max == 0 ? -1 : max);
    }
}

