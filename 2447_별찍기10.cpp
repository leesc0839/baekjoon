//
// Created by 이승철 on 2022/11/17.
//
#include <iostream>

using namespace std;
int N;
const int MX = 70;
char board[MX][MX];

void sol(int len, int idx) {
    if (len == N * 3) {
        cout << star;
        return;
    }
    for (int i = 0; i < 9; i++) {
        if (i == 4) {
            for (int r = 0; r < len; r++) {
                for (int c = 0; c < len; c++)
                    cout << ' ';
                cout << '\n';
            }
        } else
            cout << star;
        sol(len, idx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    sol(1, 0);
}

