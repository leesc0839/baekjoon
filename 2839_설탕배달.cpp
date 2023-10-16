//
// Created by 이승철 on 2022/08/15.
//
#include <iostream>
#include <algorithm>

using namespace std;
int n; // 3 ~ 5000
int cnt5;
int cnt3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cnt5 = n / 5;
    cnt3 = n / 3;
    for (int f = cnt5; f >= 0; f--) {
        for (int t = 0; t <= cnt3; t++) {
            if (f * 5 + t * 3 == n) {
                cout << f + t;
                exit(0);
            }
        }
    }
    cout << -1;

}
