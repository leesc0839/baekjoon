//
// Created by 이승철 on 2022/08/24.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, country = 1;
int map[105][105];
int dist[105][105];
bool visit[105][105];
int min_dir = 205;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
struct info {
    int r;
    int c;
    int dir;
};
queue<pair<int, int>> Q;
queue<pair<int, int>> countryQ[10005];
queue<info> q;

/*
 * n(지도의 크기 : 1~100)
 */

void flood_fill() {
    while (!Q.empty()) {
        auto cur = Q.front();
        countryQ[country].push({cur.first, cur.second});
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;
            if (visit[nr][nc] || map[nr][nc] == 0)
                continue;
            visit[nr][nc] = true;
            map[nr][nc] = country;
            Q.push({nr, nc});
        }
    }
}

void find_bfs(int cur_country) {
    auto c = q.front();
    dist[c.r][c.c] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;
            if (dist[nr][nc] != -1)
                continue;
            if (map[nr][nc] == 0) {
                q.push({nr, nc, cur.dir + 1});
                dist[nr][nc] = cur.dir + 1;
            } else if (map[cur.r][cur.c] == 0 && map[nr][nc] == cur_country) {
                dist[nr][nc] = 0;
                q.push({nr, nc, 0});
            } else if ((map[nr][nc] != cur_country)) {
                min_dir = min(min_dir, dist[cur.r][cur.c]);
            } else {
                q.push({nr, nc, cur.dir});
                dist[nr][nc] = cur.dir;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            cin >> map[r][c];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && map[i][j] != 0) {
                Q.push({i, j});
                visit[i][j] = true;
                map[i][j] = country;
                flood_fill();
                country++;
            }
        }
    }

    for (int i = 1; i < country; i++) {
        for (int r = 0; r < n; r++)
            fill(dist[r], dist[r] + n, -1);


        for (int j = 0; j < countryQ[i].size(); j++) {
            auto cur = countryQ[i].front();
            q.push({cur.first, cur.second});
            countryQ[i].pop();
        }
        find_bfs(i);
    }
    cout << min_dir;
}


