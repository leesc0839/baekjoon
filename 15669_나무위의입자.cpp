//
// Created by 이승철 on 2023/02/21.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;
ll N, M, U, V, C;
const ll MX = 100001;
const ll INF = LLONG_MAX;
vector<ll> edge[MX];
ll u_dist[MX], v_dist[MX];

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;


void init(ll start, ll *dist) {
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[start] = 0;
    pq.push({0, start});
}

void dijkstra(ll start, ll *dist) {
    init(start, dist);
    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        ll cur_node = pq.top().second;
        pq.pop();

        for (auto nxt_node: edge[cur_node]) {
            if (dist[nxt_node] <= cur_dist + 1)
                continue;
            if ((cur_node == U && nxt_node == V) || (cur_node == V && nxt_node == U))
                continue;
            dist[nxt_node] = cur_dist + 1;
            pq.push({dist[nxt_node], nxt_node});
        }
    }
}


void sol() {
    cin >> N >> M; // 입자 수, 실험 수
    for (int i = 0; i < N - 1; i++) {
        cin >> U >> V; // edge
        edge[U].emplace_back(V);
        edge[V].emplace_back(U);
    }
    for (int i = 0; i < M; i++) {
        ll ans = 0;
        cin >> U >> V >> C; // 필수 간선, 색상(0 빨강 - 짝수 , 1 검정 - 홀수)
        dijkstra(U, u_dist);
        dijkstra(V, v_dist);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j || u_dist[i] == INF || v_dist[j] == INF)
                    continue;
                if ((u_dist[i] + v_dist[j] + 1) % 2 == C)
                    ans++;
            }
        }
        cout << ans<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();

}
