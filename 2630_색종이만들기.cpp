//
// Created by 이승철 on 2022/11/16.
//
#include <iostream>

using namespace std;
const int MX = 200;
int N, board[MX][MX], ans[2];

bool check(int r, int c, int len) {
    for (int i = r; i < r + len; i++) {
        for (int j = c; j < c + len; j++)
            if (board[r][c] != board[i][j])
                return false;
    }
    return true;
}

void sol(int r, int c, int len) {
    if (check(r, c, len)) {
        ans[board[r][c]]++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + ((i / 2) * (len / 2));
        int nc = c + ((i % 2) * (len / 2));
        sol(nr, nc, len / 2);
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol(0, 0, N);
    cout << ans[0] << '\n' << ans[1];
}

