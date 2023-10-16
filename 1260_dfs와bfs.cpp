//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <queue>

using namespace std;
int n, m, s;
int board[1001][1001];
bool visit[1001];

void dfs(int v) {
    cout << v << ' ';

    for (int i = 1; i <= 1000; i++) {
        if (!visit[i] && board[v][i]) {
            visit[i] = true;
            dfs(i);
        }
    }
}

void bfs(int v) {
    queue<int> Q;
    Q.push(v);
    cout << v << ' ';
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 1; i <= 1000; i++) {
            if (!visit[i] && board[cur][i]) {
                visit[i] = true;
                Q.push(i);
                cout << i << ' ';
            }
        }
    }
}

void clear() {
    for (int i = 1; i <= 1000; i++)
        visit[i] = false;
    visit[s] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        board[start][end] = 1;
        board[end][start] = 1;
    }
    clear();
    dfs(s);
    clear();
    cout << '\n';
    bfs(s);
}