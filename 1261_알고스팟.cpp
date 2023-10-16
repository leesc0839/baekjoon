//
// Created by 이승철 on 2022/09/05.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int R, C;
char map[105][105];
int crash[105][105];
const int INF = 1e9 + 10;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void input() {
    cin >> C >> R;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
            cin >> map[i][j];
    }
}

void dijkstra() {
    for (int i = 1; i <= R; i++)
        fill(crash[i], crash[i] + C + 1, INF);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    crash[1][1] = 0;
    pq.push({crash[1][1], {1, 1}});
    while (!pq.empty()) {
        int cur_crash = pq.top().first;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;
        pq.pop();

        if (cur_r == R && cur_c == C) {
            cout << crash[R][C];
            return;
        }

        if (cur_crash != crash[cur_r][cur_c])
            continue;

        for (int i = 0; i < 4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];

            if (nr < 1 || nr > R || nc < 1 || nc > C)
                continue;

            if (map[nr][nc] == '1' && crash[nr][nc] <= crash[cur_r][cur_c] + 1)
                continue;
            if (map[nr][nc] == '0' && crash[nr][nc] <= crash[cur_r][cur_c])
                continue;

            crash[nr][nc] = (map[nr][nc] == '1') ? crash[cur_r][cur_c] + 1 : crash[cur_r][cur_c];
            pq.push({crash[nr][nc], {nr, nc}});
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    dijkstra();
}

