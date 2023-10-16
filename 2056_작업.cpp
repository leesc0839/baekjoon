//
// Created by 이승철 on 2022/08/27.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, v, out_degree,Max;
int vertex_cost[10005];
int in_degree[10005];
int ans[10005];
vector<vector<int>> edge;


/*
 * n (vertex 개수 : 3 ~ 10000)
 * 문제 조건에서 선행 조건은 자신보다 작은 수만 주어진다 하기 때문에 , acyclic 하다.
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    edge.resize(n + 1);
    for (int u = 1; u <= n; u++) {
        cin >> vertex_cost[u];
        cin >> out_degree;
        in_degree[u] = out_degree;

        for (int j = 0; j < out_degree; j++) {
            cin >> v;
            edge[v].push_back(u);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            PQ.push({vertex_cost[i], i});
    }

    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        ans[cur.second] = cur.first;

        for (auto c: edge[cur.second]) {
            in_degree[c]--;
            if (in_degree[c] == 0)
                PQ.push({vertex_cost[c] + cur.first, c});
        }
    }

    for(int i=1; i<=n; i++)
        Max=max(Max,ans[i]);

    cout<<Max;
}