//
// Created by 이승철 on 2022/12/12.
//
#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 505;
int Task, K, Dp[MX][MX];

void init() {
    // size : 2
    for (int i = 1; i < K; i++) {
        Dp[i][i + 1] = Dp[i][i] + Dp[i + 1][i + 1];
        Dp[i + 1][i] = Dp[i][i] + Dp[i + 1][i + 1];
    }
}

void fun(int size) {
    for (int i = 1; i < K; i++) {
        int start = i;
        int end = i + size - 1;
        if (end > K)
            return;
        Dp[start][end] = Dp[start][start] + min(Dp[start + 1][end], Dp[end][start + 1]);
        Dp[end][start] = Dp[end][end] + min(Dp[start][end - 1], Dp[end - 1][start]);
    }
}

void sol() {
    cin >> Task;
    while (Task--) {
        cin >> K;
        for (int i = 1; i <= K; i++)
            cin >> Dp[i][i];
        init();
        for (int i = 3; i <= K; i++)
            fun(i);
        cout << 2 * min(Dp[1][K], Dp[K][1]) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}