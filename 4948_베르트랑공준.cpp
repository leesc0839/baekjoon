//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>
#define MAX 247000
using namespace std;
bool isPrime[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(isPrime, isPrime + MAX, true);
    isPrime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i + i; j < MAX; j += i)
            isPrime[j] = false;
    }

    int tk = -1;
    while (true) {
        cin >> tk;
        if (!tk)
            break;
        int cnt = 0;
        for (int i = tk + 1; i <= tk * 2; i++) {
            if (isPrime[i])
                cnt++;
        }
        cout << cnt << '\n';
    }
}