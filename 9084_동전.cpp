//
// Created by 이승철 on 2022/08/15.
//
#include <iostream>
#include <vector>

using namespace std;
int t, n, k;
int dp[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        fill(dp, dp + 10005, 0);
        cin >> n;
        vector<int> coin;
        coin.resize(n);
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        cin >> k;
        for (int i = 0; i < n; i++) { // 동전
            dp[coin[i]] += 1;
            for (int j = coin[i] + 1; j <= k; j++) // j는 값
                dp[j] += dp[j - coin[i]];
        }
        cout<<dp[k]<<'\n';
    }
}

