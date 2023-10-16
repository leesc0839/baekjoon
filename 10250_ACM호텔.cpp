//
// Created by 이승철 on 2022/07/31.
//
#include <iostream>

using namespace std;
int TK, H, W, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TK;
    while (TK--) {
        cin >> H >> W >> N;
        N % H == 0 ? cout << H : cout << N % H;
        int back = (N % H == 0) ? (N / H) : (N / H)+1;
        back < 10 ? cout << 0 << back : cout << back;
        cout << '\n';
    }
}
