//
// Created by 이승철 on 2022/07/24.
//
#include <iostream>
#include <set>
using namespace std;
int N,returnValue;
string command;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> set;
    cin >> N;
    while (N--) {
        cin >> command;
        if (command == "ENTER") {
            returnValue += (int)set.size();
            set.clear();
        } else {
            set.insert(command);
        }
    }
    cout<<returnValue + set.size();

}
