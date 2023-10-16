//
// Created by 이승철 on 2022/08/15.
//
#include <iostream>
#include <vector>

using namespace std;
int n, k; // 동전 종류 : 1~100 , 합 : 1~10000 , 각 동전의 최대 가치 100000
int dp[100005]; // 테이블 : 가능한 횟수 저장
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // 1~k 까지 돌면서, 만들 수 있는 값들을 저장해 나가는 구조
    // 현재 cur = 3, 동전이 2이고, 1원을 만들 수 있는 방법이 있다면, dp[3(cur)] += dp[3(cur) - 2(동전)] -> 이걸 for 문으로 돈다면?
    // 동전 값을 기준 으로 for 문을 돌고, dp[cur] += dp[cur - 동전 값] 를 하면 중복 발생 X
    // 동전이 1, 2, 5 이고, 만약 동전 5로 for 문을 돌고 있는 상황 이면, 1과 2를 이용해 만들 수 있는 값들은 다 정해진 상태
    // dp[cur] += dp[cur - v[i]] -> for 문으로

    for (int coin = 0; coin < n; coin++) { // 동전
        dp[v[coin]] += 1; // 동전 * 1 은 무조건 만들 수 있는 값
        for (int cur = v[coin] + 1; cur <= k; cur++) {
            if (cur - v[coin] == 0)
                continue;
            dp[cur] += dp[cur - v[coin]];
        }
    }

    cout << dp[k];

}

