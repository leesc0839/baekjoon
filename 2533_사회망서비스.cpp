//
// Created by 이승철 on 2023/03/20.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct info {
    vector<int> child;

    info() {
        child = vector<int>();
    }
};

const int MX = 1000001;
int N, U, V, dp[MX][2];
bool visit[MX];
vector<int> edge[MX];
info tree[MX];

void init() {
    memset(dp, -1, sizeof(dp));
}

void input() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> U >> V;
        edge[U].emplace_back(V);
        edge[V].emplace_back(U);
    }
}

void make_tree_to_dfs(int v) {
    for (auto cur: edge[v]) {
        if (visit[cur])
            continue;

        visit[cur] = true;
        tree[v].child.emplace_back(cur);

        make_tree_to_dfs(cur);
    }
}

int fun(int v, int idx) {
    if (tree[v].child.empty())
        return dp[v][idx] = idx;

    if (dp[v][idx] != -1)
        return dp[v][idx];

    if (idx == 1) {
        int ret = 1;
        for (auto ch: tree[v].child)
            ret += min(fun(ch, 0), fun(ch, 1));
        return dp[v][1] = ret;
    } else {
        int ret = 0;
        for (auto ch: tree[v].child)
            ret += fun(ch, 1);
        return dp[v][0] = ret;
    }
}

void sol() {
    visit[1] = true;
    make_tree_to_dfs(1);
    cout << min(fun(1,0), fun(1,1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
}