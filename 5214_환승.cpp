#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K, M;
vector<vector<int>> edge;
int dir[101005];
queue<int> Q;

void init() {
    fill(dir, dir + 101005, -1);
    edge.resize(N + M + 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> M;
    init();

    for (int tube = 1; tube <= M; tube++) {
        for (int j = 1; j <= K; j++) {
            int station;
            cin >> station;
            edge[N + tube].push_back(station); // tube to station
            edge[station].push_back(N + tube); // station to tube
        }
    }

    Q.push(1);
    dir[1] = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (cur == N)
            break;

        for (auto nxt: edge[cur]) {
            if (dir[nxt] != -1)
                continue;
            dir[nxt] = dir[cur] + 1;
            Q.push({nxt});
        }
    }

    (dir[N] == -1)? cout << -1 : cout << dir[N]/2 + 1;

}