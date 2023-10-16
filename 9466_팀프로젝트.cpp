#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

#define MAX 100001
using namespace std;

int edge[MAX], T, N, v, ans;
bool is_group[MAX], visit[MAX];

void init() {
    fill(is_group, is_group + N + 1, false);
    fill(visit, visit + N + 1, false);
    ans = 0;
}

void input() {
    cin >> N;
    init();
    for (int u = 1; u <= N; u++) {
        cin >> v;
        edge[u] = v;

        if (u == v)
            is_group[u] = visit[u] = true;
    }
}

void find_path(int vertex) {
    vector<int> path;
    unordered_set<int> S;
    queue<int> Q;
    visit[vertex] = true;
    path.push_back(vertex);
    S.insert(vertex);
    Q.push(vertex);

    while (!Q.empty()) {
        int cur_vertex = Q.front();
        int nxt_vertex = edge[cur_vertex];
        Q.pop();

        if (S.count(nxt_vertex)) {
            for (auto iter = path.rbegin(); iter != path.rend(); iter++) {
                is_group[*iter] = true;
                if (*iter == nxt_vertex)
                    return;
            }
        }

        if (visit[nxt_vertex] || is_group[nxt_vertex])
            return;

        visit[nxt_vertex] = true;
        S.insert(nxt_vertex);
        Q.push(nxt_vertex);
        path.push_back(nxt_vertex);
    }

}

void sol() {
    for (int i = 1; i <= N; i++) {
        if (visit[i])
            continue;
        find_path(i);
    }
    for (int i = 1; i <= N; i++) {
        if (!is_group[i])
            ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        input();
        sol();
    }
}