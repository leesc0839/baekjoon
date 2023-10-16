#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;
typedef long long ll;
const int MX = 100005;
const ll INF = LLONG_MAX;
int N, M, A, B, u, v, st, ed, md;
ll C, c, ans =INF;
vector<pair<int, ll>> edge[MX];
set<ll> tmp;
vector<ll> edge_arr;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
ll dist[MX];

void init() {
    fill(dist, dist + N + 1, INF);
    dist[A] = 0;
    pq.push({0, A});
}

void input() {
    cin >> N >> M >> A >> B >> C;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        tmp.insert(c);
        edge[u].emplace_back(v, c);
        edge[v].emplace_back(u, c);
    }
    for (auto cur: tmp)
        edge_arr.push_back(cur);
    st = 0, ed = edge_arr.size() - 1, md = (st + ed) / 2;
}

bool dijkstra(ll lim) {
    init();
    while (!pq.empty()) {
        int c_vertex = pq.top().second;
        ll c_cost = pq.top().first;
        pq.pop();

        if (dist[c_vertex] != c_cost)
            continue;
        if (c_vertex == B)
            return true;

        for (auto nxt: edge[c_vertex]) {
            int n_vertex = nxt.first;
            ll edge_cost = nxt.second;

            if (edge_cost > lim || c_cost + edge_cost > C)
                continue;
            if (dist[n_vertex] <= c_cost + edge_cost)
                continue;
            dist[n_vertex] = c_cost + edge_cost;
            pq.push({dist[n_vertex], n_vertex});
        }
    }
    return false;
}

void sol() {
    while (true) {
        if (st == md && md == ed)
            break;
        if (dijkstra(edge_arr[md])) {
            ans = min(ans, edge_arr[md]);
            ed = md;
            md = (st + ed) / 2;
        } else {
            st = md + 1;
            md = (st + ed) / 2;
        }
    }
    if (ans == INF && dijkstra(edge_arr[md]))
        ans = edge_arr[md];
    (ans == INF) ? cout << -1 : cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}

