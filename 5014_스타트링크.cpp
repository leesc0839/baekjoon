//
// Created by 이승철 on 2022/09/15.
//

#include <iostream>
#include <queue>
#include <climits>

#define MAX 1000005
using namespace std;
int F, S, G, U, D, dist[MAX];
const int INF = INT32_MAX;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
    fill(dist, dist + F + 1, INF);
}

void input() {
    cin >> F >> S >> G >> U >> D;
}

void sol() {
    dist[S] = 0;
    pq.push({dist[S], S});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_stair = pq.top().second;
        pq.pop();

        if (cur_stair == G)
            break;
        if (dist[cur_stair] < cur_dist)
            continue;

        int up_stair = cur_stair + U;
        int down_stair = cur_stair - D;

        if (up_stair > 0 && up_stair <= F) {
            if (dist[up_stair] > cur_dist + 1){
                dist[up_stair] = cur_dist + 1;
                pq.push({dist[up_stair], up_stair});
            }
        }

        if (down_stair > 0 && down_stair <= F) {
            if (dist[down_stair] > cur_dist + 1){
                dist[down_stair] = cur_dist + 1;
                pq.push({dist[down_stair], down_stair});
            }
        }
    }

    dist[G] == INF ? cout << "use the stairs" : cout << dist[G];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
}

