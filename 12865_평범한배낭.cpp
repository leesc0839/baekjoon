//
// Created by 이승철 on 2023/02/23.
//
#include <iostream>
#include <algorithm>

using namespace std;
int N, K;
int W[101], V[101], dp[101][100001];

void input() {
    cin >> N >> K;
    for (int idx = 1; idx <= N; idx++)
        cin >> W[idx] >> V[idx];
}

void sol() {
    for (int weight = 1; weight <= K; weight++) { // 무게에 따라서
        for (int idx = 1; idx <= N; idx++) { // idx 번째 물건 까지 고려
            if (W[idx] <= weight) { // 넣을 수 있을 경우 : 해당 물건을 넣을 것인가 안 넣을 것인가
                dp[idx][weight] = max(dp[idx - 1][weight - W[idx]] + V[idx], dp[idx - 1][weight]);
                // 현재 weight - idx 무게, idx-1 물건 까지만 고려한 최적 가치 + idx 가치 vs
                // 현재 weight 에서 idx-1 번째 물건까지만 고려한 최적 가치
            } else { // 넣을 수 없는 경우 : 이전의 최적 가치로 대체
                dp[idx][weight] = dp[idx - 1][weight];
            }
        }
    }
    cout << dp[N][K];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}