//
// Created by 이승철 on 2022/08/17.
//
#include <iostream>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;
int p;
ll dp[35][35];
bool visit[35][35];
int dr[2] = {0, 1};
int dc[2] = {1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;
    q.push({1, 0});
    dp[1][0] = 1;
    visit[1][0] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (nr < nc || nr > 30)
                continue;
            if (!visit[nr][nc])
                q.push({nr, nc});
            visit[nr][nc] = true;
            dp[nr][nc] += dp[cur.first][cur.second];

        }
    }

    while (true) {
        cin >> p;
        if (p == 0)
            break;
        cout << dp[p][p] << '\n';
    }
}

