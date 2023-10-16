#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int V, E, K, u, v, w;
vector<pair<int, int>> edge[20005];
const int INF = 200005;
int dist[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].emplace_back(w, v);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;
    fill(dist, dist + V + 1, INF);
    dist[K] = 0;
    PQ.push({dist[K], K});

    while (!PQ.empty()) {
        int cur_weight = PQ.top().first;
        int cur_vertex = PQ.top().second;
        PQ.pop();

        if (dist[cur_vertex] < cur_weight)
            continue;

        for (auto nxt: edge[cur_vertex]) {
            int nxt_weight = nxt.first;
            int nxt_vertex = nxt.second;

            if (dist[nxt_vertex] <= dist[cur_vertex] + nxt_weight)
                continue;

            dist[nxt_vertex] = dist[cur_vertex] + nxt_weight;
            PQ.push({dist[nxt_vertex], nxt_vertex});
        }
    }

    for (int i = 1; i <= V; i++) {
        dist[i] != INF ? cout << dist[i] : cout << "INF";
        cout << '\n';
    }

}