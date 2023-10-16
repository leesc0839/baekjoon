//
// Created by 이승철 on 2023/09/17.
//
#include <iostream>

using namespace std;

int N, K;

int sol() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            cnt++;
            if (cnt == K)
                return i;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    cout << sol();

}

