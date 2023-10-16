//
// Created by 이승철 on 2022/11/01.
//

#include <iostream>

using namespace std;
int N;

void input() {
    cin >> N;
}

void hanoi(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a, 6 - a - b, n - 1); // n-1개를 a에서 6-a-b로 옮긴다.
    cout << a << ' ' << b << '\n'; // 1개를 a에서 b로 옮긴다.
    hanoi(6 - a - b, b, n - 1); // 6-a-b에서 b로 n-1개를 옮긴다.
}

void sol() {
    cout << (2 << (N - 1)) - 1 << "\n";
    hanoi(1, 3, N);
}

int main() {
    input();
    sol();
}
