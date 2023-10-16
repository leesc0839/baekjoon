//
// Created by 이승철 on 2023/03/05.
//
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int N, a, b;
const int MX = 501;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

struct info {
    int idx;
    int left;
    int right;
};
info tile[(MX * MX - MX / 2) + 1];
pair<int, int> map[MX][2 * MX];
const int INF = INT32_MAX;
int dist[MX][2 * MX];
pair<int, int> pre[MX][2 * MX];


void input() {
    cin >> N;
    for (int idx = 1; idx <= N * N - N / 2; idx++) {
        cin >> a >> b;
        tile[idx] = { idx, a, b };
    }
}

void indexing() {
    int idx = 1;
    for (int r = 0; r < N; r++) {
        if (r % 2 == 0) {
            for (int c = 0; c < 2 * N; c++) {
                if (c % 2 == 0)
                    map[r][c] = { idx, tile[idx].left };
                else {
                    map[r][c] = { idx, tile[idx].right };
                    idx++;
                }
            }
        }
        else {
            for (int c = 1; c <= 2 * (N - 1); c++) {
                if (c % 2 == 1)
                    map[r][c] = { idx, tile[idx].left };
                else {
                    map[r][c] = { idx, tile[idx].right };
                    idx++;
                }
            }
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= 2 * N)
        return true;
    if (r % 2 == 1 && (c == 0 || c == 2 * N - 1))
        return true;
    return false;
}

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++)
            dist[i][j] = INF;
    }
    dist[0][0] = 1;
    pre[0][0] = { -1, -1 };
    pq.push({ 1, {0, 0} });

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (dist[r][c] != cur_dist)
            continue;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (OOB(nr, nc))
                continue;

            if (map[r][c].first != map[nr][nc].first) {
                if (map[r][c].second != map[nr][nc].second)
                    continue;
                if (dist[nr][nc] <= cur_dist + 1)
                    continue;

                dist[nr][nc] = cur_dist + 1;
                pq.push({ dist[nr][nc], {nr, nc} });
                pre[nr][nc] = { r, c };
            }
            else {
                if (dist[nr][nc] <= cur_dist)
                    continue;

                dist[nr][nc] = cur_dist;
                pq.push({ dist[nr][nc], {nr, nc} });
                pre[nr][nc] = { r, c };
            }
        }
    }
}

void route(int r, int c) {
    stack<int> S;
    pair<int, int> idx = { r, c };
    while (true) {
        if (idx.first == -1 && idx.second == -1)
            break;
        S.push(map[idx.first][idx.second].first);
        idx = { pre[idx.first][idx.second].first, pre[idx.first][idx.second].second };
    }

    int prev = -1;
    while (!S.empty()) {
        if (prev == S.top()) {
            S.pop();
            continue;
        }
        cout << S.top() << ' ';
        prev = S.top();
        S.pop();
    }


}

void sol() {
    dijkstra();
    for (int r = N - 1; r >= 0; r--) {
        if (r % 2 == 1) {
            for (int c = 2 * N - 1; c >= 0; c--) {
                if (dist[r][c] == INF)
                    continue;

                cout << dist[r][c] << '\n';
                route(r, c);
                exit(0);
            }
        }
        else {
            for (int c = 2 * (N - 1); c >= 0; c--) {
                if (dist[r][c] == INF)
                    continue;
                cout << dist[r][c] << '\n';
                route(r, c);
                exit(0);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    indexing();
    sol();
}

