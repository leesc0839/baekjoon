//
// Created by 이승철 on 2022/08/14.
//
#include <iostream>

using namespace std;
long long n;
long long arr[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for (long long i = 4; i <= n; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;

    cout << arr[n] % 10007;

}

