//
// Created by 이승철 on 2022/09/16.
//
#include <iostream>
#include <queue>
#include <climits>

#define MAX 100001
using namespace std;
int dist[MAX];
const int INF = INT32_MAX;
int N, K;

void init() {
    fill(dist, dist + MAX, INF);
}

void input() {
    cin >> N >> K;
}

void sol() {
    dist[N] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[N], N});
    while (!pq.empty()) {
        int cur_idx = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        if (dist[cur_idx] < cur_dist)
            continue;
        if(cur_idx == K)
            break;

        for (auto nxt_idx: {cur_idx - 1, cur_idx + 1, 2 * cur_idx}) {
            if (nxt_idx < 0 || nxt_idx >= MAX)
                continue;
            if (nxt_idx == 2 * cur_idx) {
                if (dist[nxt_idx] <= cur_dist)
                    continue;
                dist[nxt_idx] = cur_dist;
                pq.push({dist[nxt_idx], nxt_idx});
            } else {
                if (dist[nxt_idx] <= cur_dist + 1)
                    continue;
                dist[nxt_idx] = cur_dist + 1;
                pq.push({dist[nxt_idx], nxt_idx});
            }
        }
    }
    cout << dist[K];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
}
