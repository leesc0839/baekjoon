//
// Created by 이승철 on 2023/03/08.
//
#include <iostream>
#include <set>

using namespace std;
const int MX = 101;
typedef long long ll;
int N;
ll arr[MX], ans[MX];
set<ll> S;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        S.insert(arr[i]);
    }
}

void fun(ll x, int idx) {
    if (idx == N) {
        for (int i = 0; i < N; i++)
            cout << ans[i] << ' ';
        exit(0);
    }

    if (x % 3 == 0 && S.count(x / 3)) {
        ans[idx] = x / 3;
        fun(x / 3, idx + 1);
    }

    if (S.count(x * 2)) {
        ans[idx] = x * 2;
        fun(x * 2, idx + 1);
    }
}

void sol() {
    for (int i = 0; i < N; i++) {
        ans[0] = arr[i];
        fun(arr[i], 1);
    }
}


int main() {
    input();
    sol();
}
