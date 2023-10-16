//
// Created by 이승철 on 2023/07/12.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, K;
vector<int> coin;

void input() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        coin.emplace_back(k);
    }
    std::sort(coin.begin(), coin.end(), greater<>());
}

int sol() {
    int answer = 0;

    for (auto cur: coin) {
        if (cur > K)
            continue;
        if (K == 0)
            return answer;

        answer += K / cur;
        K %= cur;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << sol();

}
