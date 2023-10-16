//
// Created by 이승철 on 2023/02/03.
//
#include <iostream>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
const int MX = 21;
int R, C, GOAL;
pair<int, int> start;
char map[MX][MX];
bool visit[MX][MX][1025];
int trash[MX][MX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

struct info {
    int trash;
    int dist;
    int r;
    int c;
};

queue<info> Q;

void init() {
    GOAL = 0;
    Q = queue<info>();
    memset(visit, false, sizeof(visit));
    memset(trash, false, sizeof(trash));
}

bool OOB(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return true;
    return false;
}

int sol() {

    Q.push({(1 << GOAL) -1, 0, start.first, start.second});
    while (!Q.empty()) {
        int cur_trash = Q.front().trash;
        int cur_r = Q.front().r;
        int cur_c = Q.front().c;
        int cur_dist = Q.front().dist;

        if (cur_trash == 0)
            return cur_dist;

        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cur_r + dr[dir];
            int nc = cur_c + dc[dir];
            int nxt_trash = cur_trash;

            if (OOB(nr, nc) || map[nr][nc] == 'x')
                continue;
            if ((nxt_trash & trash[nr][nc]))
                nxt_trash = nxt_trash ^ trash[nr][nc];
            if (visit[nr][nc][nxt_trash])
                continue;

            visit[nr][nc][nxt_trash] = true;
            Q.push({nxt_trash, cur_dist + 1, nr, nc});
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> C >> R;
        if (R == 0 && C == 0)
            return 0;
        init();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
                if (map[i][j] == '*') {
                    trash[i][j] = 1 << GOAL; // 1번째 쓰레기는 1, 2번째는 01 , 3번째는 001
                    GOAL++;
                } else if (map[i][j] == 'o')
                    start = {i, j};
            }
        }
        cout << sol() << '\n';
    }
}

