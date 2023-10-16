//
// Created by 이승철 on 2022/08/08.
//
#include <iostream>
#include <set>

using namespace std;
int n, m, h, a, b, cnt;
bool board[31][11];
bool isClear;
set<pair<int, int>> S;

void debug() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << " ";
        cout << '\n';
    }
}

bool checkColumn(int c) {
    int s = 0;
    for (int i = 1; i <= h; i++)
        s += board[i][c];
    if (!(s % 2))
        return true;
    else
        return false;
}

void makeLadder(int c) {
    if (c == n) {
        isClear = true;
        return;
    }
    for (int r = 1; r <= n; r++) {
        if (checkColumn(c))
            makeLadder(c + 1);
        else if (!board[r][c]) {
            board[r][c] = true;
            cnt++;
            if (checkColumn(c))
                makeLadder(c + 1);
            if(!S.count({r,c}))
                board[r][c] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        S.emplace(a, b);
        S.emplace(a, b - 1);
        S.emplace(a, b + 1);
        board[a][b] = true;
        board[a][b - 1] = true;
        board[a][b + 1] = true;
    }

    makeLadder(1);
    if (!isClear || cnt > 3)
        cout << -1;
    else
        cout << cnt;
}
