//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>

#define MAX 10001
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

    int tk, n;
    cin >> tk;
    while (tk--) {
        cin >> n;
        for (int i = n / 2; i >= 2; i--) {
            if (!isPrime[i])
                continue;

            if (isPrime[i] && isPrime[n - i]) {
                cout << i << " " << n - i << "\n";
                break;
            }
        }
    }
}
