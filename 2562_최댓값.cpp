//
// Created by 이승철 on 2023/09/17.
//
#include <iostream>
#include <algorithm>

using namespace std;
int num;

void sol() {
    int ans = 0;
    int idx;

    for (int i = 1; i <= 9; i++) {
        cin >> num;
        if (ans >= num)
            continue;
        ans = num;
        idx = i;
    }
    cout << ans << '\n' << idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sol();
}

