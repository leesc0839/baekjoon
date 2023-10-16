//
// Created by 이승철 on 2022/08/14.
//
#include <iostream>

using namespace std;
long long n;
long long arr[95][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[1][0] = 0;
    arr[1][1] = 1;

    for (long long i = 2; i <= n; i++) {
        arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
        arr[i][1] = arr[i - 1][0];
    }
    cout << arr[n][0] + arr[n][1];
}
