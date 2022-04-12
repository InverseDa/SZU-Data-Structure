//
// Created by inver on 2021/12/24.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<string> male, female;
    while (n--) {
        string name, sex;
        cin >> name >> sex;
        if (sex == "F") female.push(name);
        else male.push(name);
    }
    while (!male.empty() && !female.empty()) {
        cout << female.front() << " " << male.front() << endl;
        male.pop();
        female.pop();
    }
    if (!male.empty()) cout << "M:" << male.size() << endl;
    if (!female.empty()) cout << "F:" << female.size() << endl;
}