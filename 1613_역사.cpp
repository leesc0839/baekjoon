//
// Created by 이승철 on 2022/09/04.
//

#include <iostream>
#include <vector>

using namespace std;
int n, k, s, u, v;
bool isConnect[405][405];

void floyd() {
    for (int vertex = 1; vertex <= n; vertex++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (isConnect[i][vertex] && isConnect[vertex][j])
                    isConnect[i][j] = true;
            }
        }
    }
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        isConnect[u][v] = true;
    }
    floyd();
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> u >> v;
        if (isConnect[u][v]) {
            cout << -1 << '\n';
            continue;
        }
        if (isConnect[v][u]) {
            cout << 1 << '\n';
            continue;
        }
        cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}


