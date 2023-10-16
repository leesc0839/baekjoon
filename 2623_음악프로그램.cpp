//
// Created by 이승철 on 2022/08/28.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, vertex;
vector<vector<int>> edge;
vector<int> ans;
int in_degree[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    edge.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        vector<int> path;
        for (int j = 0; j < cnt; j++) {
            cin >> vertex;
            path.push_back(vertex);
        }

        for (int u = 0; u < cnt - 1; u++) {
            edge[path[u]].push_back(path[u + 1]);
            in_degree[path[u + 1]]++;
        }
    }

    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            Q.push(i);
    }

    while (!Q.empty()) {
        auto from = Q.front();
        Q.pop();
        ans.push_back(from);

        for (auto to: edge[from]) {
            in_degree[to]--;
            if (in_degree[to] == 0)
                Q.push(to);
        }
    }

    if (ans.size() != n)
        cout << 0;
    else
        for (auto c: ans)
            cout << c << '\n';


}
