//
// Created by 이승철 on 2023/03/21.
//
#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> info;
const int MX = 101;
int N, map[MX][MX];
int ans = INT32_MAX;
info bound = {INT32_MAX, 0}; // min max
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visit[MX][MX];
queue<info> q;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            bound.first = min(bound.first, map[i][j]);
            bound.second = max(bound.second, map[i][j]);
        }
    }
}

void init(int f, int l) {
    memset(visit, true, sizeof(visit));
    // 갈 수 있는 곳만 false
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (f <= map[i][j] && map[i][j] <= l)
                visit[i][j] = false;
    }
    visit[0][0] = true;
    q = queue<info>();
    q.push({0, 0});
}

bool OOB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N)
        return true;
    return false;
}

bool bfs(int limit) {
    for (int i = bound.first; i <= bound.second - limit; i++) {
        if (i > map[0][0] || map[0][0] > i + limit)
            continue;
        init(i, i + limit);

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (OOB(nr, nc) || visit[nr][nc])
                    continue;
                if (nr == N - 1 && nc == N - 1) {
                    ans = min(ans, limit);
                    return true;
                }

                visit[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return false;
}


void binary_search(int first, int last) {
    int mid;
    while (first <= last) {
        mid = (first + last) / 2;
        if (bfs(mid))
            last = mid - 1;
        else
            first = mid + 1;
    }
}

void sol() {
    binary_search(0, bound.second - bound.first);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}

