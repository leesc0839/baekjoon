//
// Created by 이승철 on 2022/08/01.
//
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (N == 1)
            break;
        while (N % i == 0) {
            cout << i << '\n';
            N /= i;
        }
    }
}
