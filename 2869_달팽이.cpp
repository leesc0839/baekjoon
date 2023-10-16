//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>

using namespace std;
int A, B, V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> V;
    ((V - B) % (A - B)) ? cout << ((V - B) / (A - B)) + 1 : cout << ((V - B) / (A - B));
}
