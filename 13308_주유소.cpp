#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX 2501
using namespace std;
typedef long long ll;
int N, M, u, v;
ll cost, oil_price[MAX], dist[MAX][MAX];
const ll INF = LLONG_MAX;
vector<pair<ll, int>> edge[MAX];
priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;

void init() {
    for (int i = 1; i <= N; i++)
        fill(dist[i], dist[i] + MAX, INF);
}

void input() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> oil_price[i];

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        edge[u].emplace_back(cost, v);
        edge[v].emplace_back(cost, u);
    }
}

void dijkstra() {
    dist[1][oil_price[1]] = 0;
    pq.push({dist[1][oil_price[1]], {1, oil_price[1]}});

    while (!pq.empty()) {
        ll cur_cost = pq.top().first;
        int cur_vertex = pq.top().second.first;
        int cur_min_oil_price = pq.top().second.second;
        pq.pop();

        if (dist[cur_vertex][cur_min_oil_price] < cur_cost)
            continue;

        if (cur_vertex == N) {
            cout << cur_cost;
            return;
        }

        for (auto nxt: edge[cur_vertex]) {
            int nxt_vertex = nxt.second;
            ll edge_cost = nxt.first;
            ll nxt_min_oil_price = cur_min_oil_price;
            nxt_min_oil_price = min(nxt_min_oil_price, oil_price[nxt_vertex]);

            if (dist[nxt_vertex][nxt_min_oil_price] <=
                dist[cur_vertex][cur_min_oil_price] + edge_cost * cur_min_oil_price)
                continue;

            dist[nxt_vertex][nxt_min_oil_price] = dist[cur_vertex][cur_min_oil_price] + edge_cost * cur_min_oil_price;
            pq.push({dist[nxt_vertex][nxt_min_oil_price], {nxt_vertex, nxt_min_oil_price}});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    dijkstra();
}