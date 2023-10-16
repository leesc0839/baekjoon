//
// Created by 이승철 on 2022/08/22.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
/*
 * fire, player bfs 를 따로 돌리고, fire 속도가 더 같거나 빠르 다면, player 는 탈출 히지 못한다.
 */
int t, r, c;
char board[1005][1005];
int fire_dist[1005][1005];
int player_dist[1005][1005];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, int>> player;
queue<pair<int, int>> fire;

/*
 * fire bfs
 * 전형 적인 bfs 코드
 */
void bfs_fire() {
    while (!fire.empty()) {
        auto cur = fire.front();
        fire.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c)
                continue;
            if (board[nr][nc] == '#' || fire_dist[nr][nc] >= 0)
                continue;
            fire.push({nr, nc});
            fire_dist[nr][nc] = fire_dist[cur.first][cur.second] + 1;
        }
    }
}

/*
 * player bfs
 * 특이하게도, 보통 범위를 벗어나면 잘못된 것이지만,
 * 생각을 해보면, 여기는 범위를 벗어나는 것이 목표인 문제였다.
 * 따라서 범위를 벗어나면 return을 해준다.
 * 여기서 중요한 점은, 가장 최단 거리를 출력하라 인데, 첫 번째 탈출을 하면 바로 return 해도 된다.
 * 그 이유는 bfs의 queue에 데이터들은 거리 순으로 push, pop 된다.
 * 따라서 먼저 탈출구에 도달한 것이 무조건 정답이다.
 */

bool bfs_player() {
    while (!player.empty()) {
        auto cur = player.front();
        player.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                cout << player_dist[cur.first][cur.second] + 1 << '\n';
                return true;
            }
            if (board[nr][nc] == '#' || player_dist[nr][nc] >= 0)
                continue;
            if (fire_dist[nr][nc] != -1 && fire_dist[nr][nc] <= player_dist[cur.first][cur.second] + 1)
                continue;
            player_dist[nr][nc] = player_dist[cur.first][cur.second] + 1;
            player.push({nr, nc});
        }
    }
    return false;
}

/*
 * 미리 모든 2차원 배열을 -1로 초기화 시켜 주면, visit 배열을 만들지 않아도, -1로 구분 가능하다.
 * 대신 입력할 때 board에 -1을 0으로 전환 해야 한다.
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> c >> r;
        for (int i = 0; i < r; i++) {
            fill(fire_dist[i], fire_dist[i] + c, -1);
            fill(player_dist[i], player_dist[i] + c, -1);
            fill(board[i], board[i] + c, 0);
            player = queue<pair<int, int>>();
        }
        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                board[i][j] = s[j];
                if (s[j] == '@') {
                    player.push({i, j});
                    player_dist[i][j] = 0;
                } else if (s[j] == '*') {
                    fire.push({i, j});
                    fire_dist[i][j] = 0;
                }
            }
        }

        bfs_fire();
        if (!bfs_player())
            cout << "IMPOSSIBLE\n";
    }
}
