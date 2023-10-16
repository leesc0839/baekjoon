//
// Created by 이승철 on 2023/03/11.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
const int MX = 16;
const int INF = 987654321;
int edge[MX][MX], dp[MX][1 << MX];

void input() {
    cin >> N;
    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
            cin >> edge[u][v];
}

void init() {
    memset(dp, -1, sizeof(dp));
}


int fun(int u, int mask) {
    if (mask == (1 << N) - 1) {
        if (edge[u][0] == 0)
            return INF;
        return edge[u][0];
    }

    if (dp[u][mask] != -1) // already visit, use dp
        return dp[u][mask];

    dp[u][mask] = INF;
    int &ret = dp[u][mask];

    for (int v = 0; v < N; v++) {
        if (edge[u][v] == 0) // no edge
            continue;
        if (mask & (1 << v)) // already visit
            continue;
        ret = min(ret, edge[u][v] + fun(v, mask | (1 << v)));
    }
    return ret;
}

void sol() {
    init();
    cout << fun(0, 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
