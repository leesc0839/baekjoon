//
// Created by 이승철 on 2022/11/10.
//
#include <iostream>
#include <algorithm>
#include <vector>

struct info {
    int r;
    int c;
};
using namespace std;
const int MX = 11;
int N, board[MX][MX], ans[2];
bool used[2][2 * MX];
vector<info> v[2][2 * MX];

void sol(int color, int idx, int cnt) {
    if (idx == 2 * N - 1) {
        ans[color] = max(ans[color], cnt);
        return;
    }
    for (auto cur: v[color][idx]) {
        if (used[color][cur.r - cur.c + N])
            continue;
        used[color][cur.r - cur.c + N] = true;
        sol(color, idx + 1, cnt + 1);
        used[color][cur.r - cur.c + N] = false;
    }
    sol(color, idx + 1, cnt);
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j])
                v[(i + j) % 2][i + j].push_back({i, j});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol(0, 0, 0);
    sol(1, 0, 0);
    cout << ans[0] + ans[1];
}

