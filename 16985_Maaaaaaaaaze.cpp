//
// Created by 이승철 on 2022/12/20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MX = 6, INF = 999999;
struct info {
    int l;
    int r;
    int c;
    int dist;
};
int dl[6] = {0, 0, 0, 0, 1, -1};
int dr[6] = {-1, 0, 1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};
int map[MX][MX][MX], newMap[MX][MX][MX], tmp[MX][MX], rotateIdx[MX], visit[MX][MX][MX];
vector<int> layerIdx;
int sl, sr, sc, el, er, ec, ans = INF;

void input() {
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++)
            for (int c = 0; c < 5; c++)
                cin >> map[l][r][c];
    }
    for (int i = 0; i < 5; i++)
        layerIdx.push_back(i);
}

void clearVisit() {
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++)
            for (int c = 0; c < 5; c++)
                visit[l][r][c] = false;
    }
}

bool OBB(int l, int r, int c) {
    if (l < 0 || l >= 5 || r < 0 || r >= 5 || c < 0 || c >= 5)
        return true;
    return false;
}

void bfs() {
    if (newMap[sl][sr][sc] == 0 || newMap[el][er][ec] == 0)
        return;

    queue<info> Q;
    clearVisit();
    visit[sl][sr][sc] = true;
    Q.push({sl, sr, sc, 0});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (cur.l == el && cur.r == er && cur.c == ec) {
            ans = min(ans, cur.dist);
            if (ans == 12) {
                cout << 12;
                exit(0);
            }

            return;
        }

        for (int dir = 0; dir < 6; dir++) {
            int nl = cur.l + dl[dir];
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if (OBB(nl, nr, nc) || visit[nl][nr][nc] || newMap[nl][nr][nc] == 0)
                continue;
            if (cur.dist + 1 >= ans)
                return;
            visit[nl][nr][nc] = true;
            Q.push({nl, nr, nc, cur.dist + 1});
        }
    }
}

void play() {
    for (int i = 0; i < 8; i++) {
        int brute = i;
        sc = 4 * (brute % 2);
        ec = sc ? 0 : 4;
        brute /= 2;

        sr = 4 * (brute % 2);
        er = sr ? 0 : 4;
        brute /= 2;

        sl = 4 * (brute % 2);
        el = sl ? 0 : 4;
        bfs();
    }
}

void rotate() {
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++)
            for (int c = 0; c < 5; c++)
                newMap[l][r][c] = map[layerIdx[l]][r][c];

        for (int i = 0; i < rotateIdx[l]; i++) { // 실제 회전
            for (int r = 0; r < 5; r++)
                for (int c = 0; c < 5; c++)
                    tmp[r][c] = newMap[l][4 - c][r];

            for (int r = 0; r < 5; r++)
                for (int c = 0; c < 5; c++)
                    newMap[l][r][c] = tmp[r][c];
        }
    }
}

void sol() {
    // rotateIdx 정해짐
    do {
        for (int i = 0; i < 1023; i++) {
            int brute = i;
            for (int j = 0; j < 5; j++) {
                rotateIdx[j] = brute % 4;
                brute /= 4;
            }
            rotate();
            play();
        }
    } while (next_permutation(layerIdx.begin(), layerIdx.end()));

    ans == INF ? cout << -1 : cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();

}
