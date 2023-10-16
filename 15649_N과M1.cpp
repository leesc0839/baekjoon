//
// Created by 이승철 on 2023/09/17.
//

#include <iostream>

using namespace std;
const int MX = 10;
int n, m, arr[MX];
bool visit[MX];

void sol(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visit[i])
            continue;
        visit[i] = true;
        arr[cnt] = i;
        sol(cnt + 1);
        visit[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    sol(0);
}