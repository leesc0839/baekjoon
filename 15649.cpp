//
// Created by 이승철 on 2022/07/19.
//

#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visit[10];

void dfs(int idx) {
    if (m == idx) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            arr[idx] = i;
            visit[i] = true;
            dfs(idx+1);
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dfs(0);
}