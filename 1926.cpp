//
// Created by 이승철 on 2022/07/07.
//
#include <iostream>
#include <queue>

using namespace std;

#define R first // 행
#define C second // 열

int board[502][502];
bool visit[502][502];
int r, c;
int maxSize;
int drawCnt;
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;

void bfs() {
    int currentSize = 0;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        currentSize++;
        for (int dir = 0; dir < 4; dir++) {
            int nc = cur.C + dc[dir];
            int nr = cur.R + dr[dir];
            if (nc < 0 || nc >= c || nr < 0 || nr >= r) continue;
            if (visit[nr][nc] || board[nr][nc] == 0)continue;
            visit[nr][nc] = 1; // 이렇게 push 할 때 visit 을 꼭 해주자 ! Pop 말고 push 할 때 visit을 하자
            Q.push({nr, nc});
        }
    }

    if (maxSize < currentSize)
        maxSize = currentSize;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visit[i][j] || board[i][j] == 0)
                continue;
            visit[i][j] = 1;
            Q.push({i, j});
            drawCnt++;
            bfs();
        }
    }

    cout << drawCnt << '\n' << maxSize;


}