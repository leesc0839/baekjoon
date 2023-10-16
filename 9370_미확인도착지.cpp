//
// Created by 이승철 on 2023/02/19.
//
#include <iostream>
#include <queue>
#include <set>

using namespace std;
int T, n, m, t, s, g, h, a, b, d, x;
const int INF = INT32_MAX;
const int MX = 2001;
int dist[MX], gtod[MX], htod[MX];
vector<pair<int, int>> edge[MX];
set<int> ans;
set<int> dest;


void init() {
    ans.clear();
    dest.clear();
    for (int i = 1; i <= n; i++)
        edge[i].clear();

    fill(dist, dist + n + 1, INF);
    fill(gtod, gtod + n + 1, INF);
    fill(htod, htod + n + 1, INF);
}

void dijkstra(int start, int *ds) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    ds[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (ds[cur] != cur_dist)
            continue;

        for (auto e: edge[cur]) {
            int nxt = e.first;
            int weight = e.second;

            if (ds[nxt] <= cur_dist + weight)
                continue;

            ds[nxt] = cur_dist + weight;
            pq.push({ds[nxt], nxt});
        }
    }
}

void sol() {
    cin >> T;
    while (T--) {
        cin >> n >> m >> t; // node, edge, dest cnt
        cin >> s >> g >> h;// start, essential edge
        init();

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d; // edge info
            edge[a].emplace_back(b, d);
            edge[b].emplace_back(a, d);
        }
        for (int i = 0; i < t; i++) {
            cin >> x; // dest info
            dest.insert(x);
        }

        dijkstra(s, dist); // 일반 dijkstra
        int stog_dist = dist[g];
        int stoh_dist = dist[h];
        int gh_dist;
        for (auto d: edge[g]) {
            if (d.first == h) {
                gh_dist = d.second;
                break;
            }
        }

        dijkstra(g, gtod);
        dijkstra(h, htod);


        for (auto destination: dest) {
            int normal = dist[destination];
            int gh = stog_dist + gh_dist + htod[destination];
            int hg = stoh_dist + gh_dist + gtod[destination];
            if (normal == min(gh, hg))
                ans.insert(destination);
        }

        for (auto cur: ans)
            cout << cur << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();

}

