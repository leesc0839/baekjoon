//
// Created by 이승철 on 2022/08/23.
//
#include <iostream>
#include <queue>

using namespace std;
int r, c; // 1 ~ 1000
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char map[1005][1005]; // 입력 시 공백이 없어 char
int dist[1005][1005][2]; // r, c, crash 여부

struct info {
    int r;
    int c;
    bool crash;
};
queue<info> Q; // 구조체 를 이용해 큐에 r, c, crash 여부를 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }

    Q.push({1, 1, false});
    dist[1][1][0] = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (cur.r == r && cur.c == c) {
            cur.crash ? cout << dist[r][c][1] : cout << dist[r][c][0];
            exit(0);
        }

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr < 1 || nr > r || nc < 1 || nc > c)
                continue;

            if (map[nr][nc] == '1') { // 벽일 때
                if (cur.crash) // 이미 부신 상황이면 continue
                    continue;
                if (dist[nr][nc][1] > 0) // 동일 상황에 이미 방문한 상황 continue
                    continue;
                Q.push({nr, nc, true}); // 벽을 통과 하려면, 부셔야 하니 crash를 true로 queue에 push
                dist[nr][nc][1] = dist[cur.r][cur.c][0] + 1; // 전에 부신적 없고, 이제 벽을 부시는 경우
            } else { // 벽이 아닐 때
                if (cur.crash) { // 벽이 아닐 때 이미 부신 적 있는 경우
                    if (dist[nr][nc][1] > 0) // 동일 상황 방문된 상황이면 continue
                        continue;
                    Q.push({nr, nc, true});
                    dist[nr][nc][1] = dist[cur.r][cur.c][1] + 1;
                } else { // 벽이 아닐 때 부신 적이 없는 경우
                    if (dist[nr][nc][0] > 0) // 동일 상황 continue
                        continue;
                    Q.push({nr, nc, false});
                    dist[nr][nc][0] = dist[cur.r][cur.c][0] + 1;
                }
            }
        }
    }
    cout << "-1";

}
