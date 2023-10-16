#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
const int MX = 13;
int map[MX][MX], map2[MX][MX];
vector<pair<int, int>> ety;
vector<pair<int, int>> virus;
vector<int> v;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                ety.emplace_back(i, j);
            else if (map[i][j] == 2)
                virus.emplace_back(i, j);
        }
    }
}

void init() {
    v.resize(ety.size());
    for (int i = 0; i < ety.size() - 3; i++)
        v[i] = 0;
    for (int i = ety.size() - 3; i < ety.size(); i++)
        v[i] = 1;
}

void copy() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            map2[i][j] = map[i][j];

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1)
            map2[ety[i].first][ety[i].second] = 1;
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M)
        return true;
    return false;
}

int bfs() {
    queue<pair<int, int>> Q;
    for (auto cur: virus) {
        Q.emplace(cur.first, cur.second);
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];

            if (OOB(nr, nc) || map2[nr][nc] != 0)
                continue;

            map2[nr][nc] = 2;
            Q.push({nr, nc});
        }
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map2[i][j] == 0)
                ret++;
        }
    }
    return ret;
}

int sol() {
    int answer = 0;
    do {
        copy();
        answer = max(answer, bfs());
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    cout << sol();
}
