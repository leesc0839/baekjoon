//
// Created by 이승철 on 2022/08/10.
//
#include <iostream>

using namespace std;
int board[10][10];
bool isr[10][10], isc[10][10], iss[3][3][10], isPossible; // 행, 열, 사각형

bool checkClear() {
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j <= 9; j++)
            if (!isr[i][j] || !isc[i][j])
                return false;
    }
    for (int e = 1; e <= 9; e++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                if (!iss[i][j][e])
                    return false;
        }
    }
    return true;
}

void backtrack(int r, int c) {
    if (isPossible)
        return;

    if (!isPossible && r == 8 && c == 8) {
        if (checkClear()) {
            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < 9; c++) {
                    cout << board[r][c];
                }
                cout << '\n';
            }
            isPossible = true;
        }
        return;
    }

    while (board[r][c] != 0) {
        c += 1;
        if (c == 9) {
            r += 1;
            c = 0;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (!isr[r][i] && !isc[c][i] && !iss[r / 3][c / 3][i]) {
            isr[r][i] = isc[c][i] = iss[r / 3][c / 3][i] = true;
            board[r][c] = i;

            if (c == 8)
                backtrack(r + 1, 0);
            else
                backtrack(r, c + 1);

            if (isPossible)
                return;

            isr[r][i] = isc[c][i] = iss[r / 3][c / 3][i] = false;
            board[r][c] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int r = 0; r < 9; r++) { // 행
        string s;
        cin >> s;
        for (int c = 0; c < 9; c++) { // 열
            int elem = s[c] - '0';
            board[r][c] = elem;
            isr[r][elem] = isc[c][elem] = true;
            iss[r / 3][c / 3][elem] = true;
        }
    }
    backtrack(0, 0);
}

