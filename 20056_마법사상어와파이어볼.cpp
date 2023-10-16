//
// Created by 이승철 on 2023/03/02.
//
#include <iostream>
#include <queue>

using namespace std;
struct info {
    int r;
    int c;
    int m;
    int s;
    int d;
};

struct mapinfo {
    int cnt;
    int m;
    int s;
    int odd;
    int even;
    int d;
};

const int MX = 55;
const int MXs = 1001;
int N, M, K, r, c, m, s, d;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

queue<info> Q;
mapinfo map[MX][MX];

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = {0, 0, 0, 0, 0};
}

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        Q.push({r - 1, c - 1, m, s, d});
    }
}

void push() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (map[i][j].cnt == 0)
                continue;
            else if (map[i][j].cnt == 1) {
                Q.push({i, j, map[i][j].m, map[i][j].s, map[i][j].d});
            } else {
                if (map[i][j].m / 5 == 0)
                    continue;
                if (map[i][j].even == 0 || map[i][j].odd == 0) {
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 0});
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 2});
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 4});
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 6});
                } else {
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 1});
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 3});
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 5});
                    Q.push({i, j, map[i][j].m / 5, map[i][j].s / map[i][j].cnt, 7});
                }
            }
        }
}

int ans() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j].cnt == 0)
                continue;
            else if (map[i][j].cnt == 1)
                ans += map[i][j].m;
            else
                ans += map[i][j].m / 5 * 4;
        }
    }
    return ans;
}

void sol() {
    for (int i = 0; i < K; i++) {
        init();
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            int nr = (cur.r + cur.s * dr[cur.d] + MXs * N) % N;
            int nc = (cur.c + cur.s * dc[cur.d] + MXs * N) % N;

            map[nr][nc].cnt++;
            map[nr][nc].m += cur.m;
            map[nr][nc].s += cur.s;
            map[nr][nc].d += cur.d;
            (cur.d % 2) ? map[nr][nc].odd++ : map[nr][nc].even++;
        }
        push();
    }
    cout << ans();
}

int main() {
    input();
    sol();
}

