//
// Created by 이승철 on 2023/09/17.
//
#include <iostream>
#include <cstring>

using namespace std;
int n;
const int MX = 25;
int dp[MX];

int sol(int n) {
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = sol(n - 1) + sol(n - 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;

    cout << sol(n);
}

