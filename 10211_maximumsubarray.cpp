//
// Created by 이승철 on 2022/08/16.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n; // n 배열의 크기 : 1 ~ 1000
int dp[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        v.resize(n + 1);
        fill(dp, dp + 1005, 0);
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        for (int i = 1; i <= n; i++) { // 끝을 기준 으로 본다.
            dp[i] = max(v[i], dp[i - 1] + v[i]); // i가 가장 수열의 끝인 상황 -> v[i] 또는 dp[i-1] + v[i] 중 큰 값이 가장 큰 값
        }

        cout << *max_element(dp+1, dp + n + 1) << '\n';
    }
}
