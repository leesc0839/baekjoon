//
// Created by 이승철 on 2023/10/05.
//

#include <iostream>

using namespace std;
const int MX = 70;
int N;
char board[MX][MX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
}

bool check(int r, int c, int size, char color) {
    for (int i = r; i < r + size; i++)
        for (int j = c; j < c + size; j++)
            if (color != board[i][j])
                return false;
    return true;
}

void sol(int r, int c, int size) {
    if (check(r, c, size, board[r][c])) {
        cout << board[r][c];
        return;
    }
    cout << "(";
    sol(r, c, size / 2);
    sol(r, c + size / 2, size / 2);
    sol(r + size / 2, c, size / 2);
    sol(r + size / 2, c + size / 2, size / 2);
    cout << ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol(0, 0, N);
}
