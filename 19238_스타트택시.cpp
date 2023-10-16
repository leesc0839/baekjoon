//
// Created by 이승철 on 2022/08/23.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, engine, player_r, player_c, guest_r, guest_c, dest_r, dest_c;
int map[25][25];
int dir[25][25];
bool visit[25][25];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
vector<pair<int, int>> destination;
int guest_num[25][25];

void clear() {
    for (int i = 1; i <= n; i++) {
        fill(dir[i], dir[i] + n + 1, 0);
        fill(visit[i], visit[i] + n + 1, 0);
    }
}

void bfs_destination(int r, int c) {
    queue<pair<int, int>> Q;
    int dest_n = guest_num[r][c];
    pair<int, int> dest = destination[dest_n];

    Q.push({r, c});
    visit[r][c] = true;
    dir[r][c] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (cur.first == dest.first && cur.second == dest.second) {
            engine -= dir[cur.first][cur.second];
            if (engine < 0) {
                cout << "-1";
                exit(0);
            }
            engine += 2 * dir[cur.first][cur.second];
            player_r = cur.first;
            player_c = cur.second;
            clear();
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > n)
                continue;
            if (map[nr][nc] == 1 || visit[nr][nc])
                continue;

            Q.push({nr, nc});
            visit[nr][nc] = true;
            dir[nr][nc] = dir[cur.first][cur.second] + 1;
        }
    }
    cout << "-1";
    exit(0);
}
/*
 * 최단 거리가 같은 경우, 가장 적은 행, 행이 같다면 가장 적은 열로 탑승을 시켜야 하기 때문에
 * priority queue 를 이용해 보았다.
 * struct를 쓰면 더 편하겠지만, 우선은 빨리 풀어보고 싶어 pair를 이중으로 사용하였다.
 * first에는 최단거리, 그리고 행 열을 저장하여
 * 최단거리가 같을 때, 자동적으로 적은 행, 적은 열이 앞으로 정렬 되게 끔 하였다.
 */
void bfs_guest(int r, int c) {

    queue<pair<int, int>> Q;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    Q.push({r, c});
    visit[r][c] = true;
    dir[r][c] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (map[cur.first][cur.second] == 2)
            pq.push({dir[cur.first][cur.second],{cur.first, cur.second}});

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > n)
                continue;
            if (map[nr][nc] == 1 || visit[nr][nc]) // 벽 이미 방문
                continue;

            Q.push({nr, nc});
            visit[nr][nc] = true;
            dir[nr][nc] = dir[cur.first][cur.second] + 1;
        }
    }

    if (pq.empty()) {
        cout << "-1";
        exit(0);
    } else {
        auto cur = pq.top();
        engine -= cur.first;
        if (engine < 0) {
            cout << -1;
            exit(0);
        }

        map[cur.second.first][cur.second.second] = 0;
        clear();
        bfs_destination(cur.second.first, cur.second.second);
        return;
    }


}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> engine;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++)
            cin >> map[r][c];
    }
    cin >> player_r >> player_c;
    destination.resize(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> guest_r >> guest_c >> dest_r >> dest_c;
        map[guest_r][guest_c] = 2; // guest == 2
        guest_num[guest_r][guest_c] = i;
        destination[i] = {dest_r, dest_c};
    }

    for (int i = 1; i <= m; i++) {
        bfs_guest(player_r, player_c);
    }


    cout << engine;
}
