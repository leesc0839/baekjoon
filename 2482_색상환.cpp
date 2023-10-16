//
// Created by 이승철 on 2023/03/04.
//
#include <iostream>

using namespace std;

int N, K;
const int MOD = 1000000003;
int dp[1001][1001];

void input() {
    cin >> N >> K;
}

void sol() {
    for (int idx = 1; idx <= N; idx++) {
        dp[idx][1] = idx;
        dp[idx][0] = 1;
    }

    for (int idx = 2; idx <= N; idx++) {
        for (int color = 2; color <= K; color++) {
            dp[idx][color] = (dp[idx - 2][color - 1] + dp[idx - 1][color]) % MOD;
        }
    }
    cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}

