//
// Created by 이승철 on 2023/01/17.
//
#include <iostream>
#include <queue>

using namespace std;

const int MX = 51;
char map[MX][MX];
int N;
pair<int, int> start;
priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;
priority_queue<int, vector<int>, greater<>> ans;
int dist[MX][MX][4];
int INF = INT32_MAX;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int dir = 0; dir < 4; dir++)
                dist[i][j][dir] = INF;
        }
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == '#')
                start = {i, j};
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N)
        return true;
    return false;
}

void sol() {
    for (int dir = 0; dir < 4; dir++) {
        dist[start.first][start.second][dir] = 0;
        pq.push({{0,           dir},
                 {start.first, start.second}});
    }

    while (!pq.empty()) {
        int curM = pq.top().first.first;
        int curD = pq.top().first.second;
        int curR = pq.top().second.first;
        int curC = pq.top().second.second;
        //int curM = dist[curR][curC][curD];
        pq.pop();

        int nxtR = curR + dr[curD];
        int nxtC = curC + dc[curD];
        int turnL = (curD + 1 + 4) % 4;
        int turnR = (curD - 1 + 4) % 4;

        if (OOB(nxtR, nxtC) || map[nxtR][nxtC] == '*')
            continue;

        if (map[nxtR][nxtC] == '!') {
            if (dist[nxtR][nxtC][curD] > curM) {
                dist[nxtR][nxtC][curD] = curM;
                pq.push({{curM,curD}, {nxtR, nxtC}});
            }
            if (dist[nxtR][nxtC][turnL] > curM + 1) {
                dist[nxtR][nxtC][turnL] = curM + 1;
                pq.push({{curM,turnL}, {nxtR, nxtC}});
            }
            if (dist[nxtR][nxtC][turnR] > curM + 1) {
                dist[nxtR][nxtC][turnR] = curM + 1;
                pq.push({{curM,turnR}, {nxtR, nxtC}});
            }
        } else if (map[nxtR][nxtC] == '.') {
            if (dist[nxtR][nxtC][curD] > curM) {
                dist[nxtR][nxtC][curD] = curM;
                pq.push({{curM,curD}, {nxtR, nxtC}});
            }
        } else if (map[nxtR][nxtC] == '#') {
            if (dist[nxtR][nxtC][curD] > curM)
                ans.push(curM);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
    cout << ans.top();
}
