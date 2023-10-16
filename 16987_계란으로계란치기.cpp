//
// Created by 이승철 on 2022/11/02.
//
#include <iostream>
#include <algorithm>

#define MAX 8
using namespace std;
int N, d, w, ans;
pair<int, int> egg[MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d >> w;
        egg[i] = {d, w};
    }
}

void sol(int cnt, int idx) { // idx 치는 계란, i 칠 계란
    ans = max(ans, cnt);
    if (idx == N)
        return;

    if (egg[idx].first <= 0) {
        sol(cnt, idx + 1);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (i == idx || egg[i].first <= 0)
            continue;
        int tmp = 0;
        egg[idx].first -= egg[i].second;
        egg[i].first -= egg[idx].second;
        if (egg[idx].first <= 0)
            tmp++;
        if (egg[i].first <= 0)
            tmp++;
        sol(cnt + tmp, idx + 1);
        egg[idx].first += egg[i].second;
        egg[i].first += egg[idx].second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol(0, 0);
    cout << ans;
}
