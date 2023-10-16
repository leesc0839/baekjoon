//
// Created by 이승철 on 2023/08/30.
//
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MX = 10005;
int K, N, mx;
int arr[MX];

void input() {
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
}

bool check(ll l) {
    ll cnt = 0;
    for (int i = 0; i < K; i++)
        cnt += arr[i] / l;

    return cnt >= N;
}

ll sol() {
    ll answer = 0;
    ll st = 1, ed = mx;
    while (st <= ed) {
        ll md = (st + ed + 1) / 2;
        if (check(md)) {
            answer = max(answer, md);
            st = md + 1;
        } else
            ed = md - 1;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << sol();
}
