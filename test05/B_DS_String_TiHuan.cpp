//
// B. DS串应用--串替换
//

#include <iostream>
#include <string>

using namespace std;

class myString {
private:
    string mainstr;
    int size;

public:
    myString();

    ~myString();

    void SetVal(string sp);

    int KMPFindSubstr(string p, int pos);

    int KMPFind(string p, int pos, int next[]);

    void GetNext(string p, int next[]);
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
    if (j >= p.size()) return i - j;
    else return -1;  //否则 匹配失败 返回-1
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str, p1, p2;
        cin >> str >> p1 >> p2;
        int pos = 0, *next = new int[p1.size()];
        myString mainString;
        mainString.SetVal(str);
        mainString.GetNext(p1, next);
        pos = mainString.KMPFind(p1, pos, next);
        cout << str << endl;
        if (pos > 0) {
            str = str.substr(0, pos) + p2 + str.substr(pos + 2);
            cout << str << endl;
        } else if (pos == 0) {
            str = p2 + str.substr(pos + 3);
            cout << str << endl;
        } else {
            cout << str << endl;
        }
    }
}