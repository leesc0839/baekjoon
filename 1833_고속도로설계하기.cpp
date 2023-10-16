#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, weight, ans;
int parent[205];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;
vector<pair<int, int>> new_road;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    parent[x] = y;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            cin >> weight;
            if (v <= u)
                continue;
            if (weight < 0) {
                ans += -1 * weight;
                if (find(u) != find(v))
                    merge(u, v);
            } else
                edge.push({weight, {u, v}});
        }
    }

    while (!edge.empty()) {
        int cost = edge.top().first;
        int from = edge.top().second.first;
        int to = edge.top().second.second;
        edge.pop();

        if (find(from) == find(to))
            continue;

        merge(from, to);
        ans += cost;
        new_road.emplace_back(from, to);
    }

    cout << ans << ' ' << new_road.size() << '\n';
    for (auto c: new_road)
        cout << c.first << ' ' << c.second << '\n';
}