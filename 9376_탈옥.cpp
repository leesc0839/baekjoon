//
// Created by 이승철 on 2023/03/19.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef tuple<int, int, int> info;

int T, R, C;
const int MX = 105;
const int INF = INT32_MAX;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int dist[MX][MX][3];
char map[MX][MX];
vector<pair<int, int>> pri;
priority_queue<info, vector<info>, greater<>> pq;

void clear() {
    for (int i = 0; i < R + 2; i++) {
        for (int j = 0; j < C + 2; j++)
            for (int k = 0; k < 3; k++)
                dist[i][j][k] = INF;
    }
}

void init() {
    pri.clear();
    clear();
}

bool OOB(int r, int c) {
    if (r < 0 || r > R + 1 || c < 0 || c > C + 1)
        return true;
    return false;
}

void dijkstra(int r, int c, int i) {
    dist[r][c][i] = 0;
    pq.push({0, r, c});

    while (!pq.empty()) {
        auto cur = pq.top();
        int crash = get<0>(cur);
        int cur_r = get<1>(cur);
        int cur_c = get<2>(cur);

        pq.pop();

        if (dist[cur_r][cur_c][i] != crash)
            continue;

        for (int dir = 0; dir < 4; dir++) {
            int nr = cur_r + dr[dir];
            int nc = cur_c + dc[dir];

            if (OOB(nr, nc) || map[nr][nc] == '*')
                continue;

            if (map[nr][nc] == '#') {
                if (dist[nr][nc][i] <= dist[cur_r][cur_c][i] + 1)
                    continue;
                dist[nr][nc][i] = crash + 1;
                pq.push({dist[nr][nc][i], nr, nc});
            } else {
                if (dist[nr][nc][i] <= dist[cur_r][cur_c][i])
                    continue;
                dist[nr][nc][i] = crash;
                pq.push({crash, nr, nc});
            }
        }
    }
}

void fun() {
    int ans = INT32_MAX;

    //prisoner
    for (int i = 0; i < 2; i++)
        dijkstra(pri[i].first, pri[i].second, i);
    //sang
    dijkstra(0, 0, 2);

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int sum = 0;
            if (dist[i][j][0] == INF || dist[i][j][1] == INF || dist[i][j][2] == INF)
                continue;
            if (map[i][j] == '*')
                continue;
            sum += dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
            if (map[i][j] == '#')
                sum -= 2;
            ans = min(ans, sum);
        }
    }
    cout << ans << "\n";
}

void sol() {
    cin >> T;
    while (T--) {
        cin >> R >> C;
        init();
        // .으로 감싸기
        for (int i = 0; i <= R + 1; i++) {
            for (int j = 0; j <= C + 1; j++) {
                if (i == 0 || j == 0 || i == R + 1 || j == C + 1)
                    map[i][j] = '.';
            }
        }
        //정상 입력
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> map[i][j];
                if (map[i][j] == '$')
                    pri.emplace_back(i, j);
            }
        }
        fun();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}
