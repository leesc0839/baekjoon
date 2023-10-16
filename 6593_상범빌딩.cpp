//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int dr[6] = {-1, 0, 1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};
int dl[6] = {0, 0, 0, 0, 1, -1};
int l, r, c, sr, sc, sl, er, ec, el;
char board[35][35][35];
bool visit[35][35][35];
int dist[35][35][35];

/*
 * S : 83 , E : 69
 * # : 35 , . : 46
 */

void clear() {
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            for(int k=0; k<l; k++){
                board[i][j][k] = 0;
                visit[i][j][k] = false;
                dist[i][j][k] = 0;
            }
        }
    }
}

void bfs(int R, int C, int L) {
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{R, C}, L});
    visit[R][C][L] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++) {
            int nr = cur.first.first + dr[i];
            int nc = cur.first.second + dc[i];
            int nl = cur.second + dl[i];

            if (nr < 0 || nr >= r || nc < 0 || nc >= c || nl < 0 || nl >= l)
                continue;
            if (visit[nr][nc][nl] || board[nr][nc][nl] == 35)
                continue;
            if (nr == er && nc == ec && nl == el) {
                cout << "Escaped in " << dist[cur.first.first][cur.first.second][cur.second] + 1
                     << " minute(s).\n";
                dist[nr][nc][nl] = dist[cur.first.first][cur.first.second][cur.second] + 1;
                return;
            }
            Q.push({{nr, nc}, nl});
            visit[nr][nc][nl] = true;
            dist[nr][nc][nl] = dist[cur.first.first][cur.first.second][cur.second] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> l >> r >> c;
        if (!l && !r && !c)
            return 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                string s;
                cin >> s;
                for (int k = 0; k < c; k++) {
                    board[j][k][i] = s[k];
                    if (s[k] == 83) {
                        sr = j;
                        sc = k;
                        sl = i;
                    } else if (s[k] == 69) {
                        er = j;
                        ec = k;
                        el = i;
                    }
                }
            }
        }

        bfs(sr, sc, sl);
        if (dist[er][ec][el] == 0)
            cout << "Trapped!\n";
        clear();
    }


}
