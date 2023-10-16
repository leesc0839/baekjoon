//
// Created by 이승철 on 2023/09/17.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;

// x^2 + y^2 = n
void sol() {
    for (int x = 0; x < 34; x++) {
        for (int y = 0; y < 34; y++) {
            int num = x * x + y * y;
            if (num > n)
                break;
            if (y > x)
                swap(x, y);
            if (num == n) {
                cout << 0 << ' ' << 0 << '\n';
                cout << x << ' ' << y << '\n';
                cout << x - y << ' ' << x + y << '\n';
                cout << -y << ' ' << x << '\n';
                return;
            }
        }
    }
    cout << "Impossible";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sol();
}