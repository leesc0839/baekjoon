//
// Created by 이승철 on 2022/11/16.
//
#include <iostream>

using namespace std;
const int MX = 3000;
int N, board[MX][MX], ans[3];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
}

bool pos(int len, int r, int c) {
    for (int i = r; i < r + len; i++) {
        for (int j = c; j < c + len; j++) {
            if (board[r][c] != board[i][j])
                return false;
        }
    }
    return true;
}

void sol(int len, int r, int c) {
    if (pos(len, r, c)) {
        ans[board[r][c] + 1]++;
        return;
    }
    for (int i = 0; i < 9; i++) {
        int nr = r + (i / 3) * (len / 3);
        int nc = c + (i % 3) * (len / 3);
        sol(len / 3, nr, nc);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol(N, 0, 0);
    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';
}
