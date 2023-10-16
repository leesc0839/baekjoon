//
// Created by 이승철 on 2023/09/17.
//

#include <iostream>

using namespace std;
string str;

bool sol() {
    for (int i = 0; i < str.size() / 2; i++) {
        int front = i;
        int back = str.size() - i - 1;

        if (str[front] != str[back])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    sol() ? cout << "true" : cout << "false";
}