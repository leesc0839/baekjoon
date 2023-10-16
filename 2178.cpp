#include <iostream>
#include <queue>

#define R first
#define C second
using namespace std;

string board[101];
int dis[101][101];
int r, c;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        cin >> board[i];

    for (int i = 0; i < r; i++)
        fill(dis[i], dis[i] + c, -1); // 초기 설정


    queue<pair<int, int>> Q;
    dis[0][0] = 0; // 초기 방문 설정
    Q.push({0, 0}); // 초기 push
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.R + dr[i];
            int nc = cur.C + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (dis[nr][nc] > -1 || board[nr][nc] != '1') continue;

            dis[nr][nc] = dis[cur.R][cur.C] + 1; // push 할 때 visit 을 꼭 해주자.
            Q.push({nr, nc});
        }
    }
    cout << dis[r-1][c-1]+1; // 처음에 0으로 시작 했음.


}