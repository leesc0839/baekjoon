//
// Created by 이승철 on 2023/09/23.
//

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MX = 1000005;
int N, M;
ll arr[MX], st, ed;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        ed = max(ed, arr[i]);
    }
}

bool check(ll h) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] - h > 0)
            sum += arr[i] - h;
    }
    return sum >= M;
}

ll sol() {
    while (st < ed) {
        ll mid = (st + ed + 1) / 2;
        if(check(mid))
            st = mid;
        else
            ed = mid - 1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << sol();
}
