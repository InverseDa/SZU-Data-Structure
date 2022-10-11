//
// A. DS串应用--KMP算法
//

#include <iostream>
#include <string>

using namespace std;

class myString {
private:
    string mainstr;
    int size;

    void GetNext(string p, int next[]);

    int KMPFind(string p, int pos, int next[]);

public:
    myString();

    ~myString();

    void SetVal(string sp);

    int KMPFindSubstr(string p, int pos);
};

myString::myString() {
    size = 0;
    mainstr = "";
}

myString::~myString() {
    size = 0;
    mainstr = "";
}

void myString::SetVal(string sp) {
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}

int myString::KMPFindSubstr(string p, int pos) {
    int L = p.length();
    int *next = new int[L];
    GetNext(p, next);
    for (int i = 0; i < L; i++) {
        cout << next[i] << ' ';
    }
    cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete[] next;
    return v;
}

void myString::GetNext(string p, int *next) {
    int i = 0, k = -1;
    next[0] = -1;
    while (i < p.size() - 1) {
        if (p[i] == p[k] || k == -1) next[++i] = ++k;
        else k = next[k];
    }
}

int myString::KMPFind(string p, int pos, int *next) {
    int i = 0, j = 0;
    while (i < this->size && j < (int) p.size()) {
        if (j == -1 || p[j] == mainstr[i]) {
            i++;
            j++;
        } else j = next[j];
    }
    pos = i - j + 1;
    if (j >= p.size()) return pos;
    else return 0;  //否则 匹配失败 返回0
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str, pat;
        int pos;
        cin >> str >> pat;
        myString mainString;
        mainString.SetVal(str);
        pos = mainString.KMPFindSubstr(pat, pos);
        cout << pos << endl;
    }
}