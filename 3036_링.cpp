//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ringCnt;
    int firstRadius;
    int radius;
    cin >> ringCnt;
    --ringCnt;
    cin >> firstRadius;
    while (ringCnt--) {
        cin >> radius;
        int curGcd = gcd(radius, firstRadius);
        cout << firstRadius / curGcd <<'/' << radius/curGcd <<'\n';
    }
}