//
// Created by 이승철 on 2023/06/20.
//
#include <iostream>

using namespace std;

int N;
typedef long long ll;
const ll mod = 1000000000;
ll dp[105][10];

void input() {
    cin >> N;
}

void init() {
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i < 9; i++)
        dp[2][i] = 2;

    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][9] = 1;
};

void sol(int n) {
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][1] % mod;
            else if (j == 9)
                dp[i][j] = dp[i - 1][8] % mod;
            else
                dp[i][j] = ((dp[i - 1][j - 1] % mod) + (dp[i - 1][j + 1] % mod)) % mod;
        }
    }

    ll ret = 0;
    for (int i = 0; i <= 9; i++)
        ret = (ret + dp[n][i]) % mod;


    cout << ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    init();
    sol(N);

}
