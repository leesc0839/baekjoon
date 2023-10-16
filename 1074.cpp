#include <iostream>
#include <cmath>

using namespace std;
int N, R, C;
int range;
int k;

void findBoard(int n, int r, int c) {
    if (n == 0) // base condition
        return;
    range = (int) pow(2, n - 1);
    if (c >= range && r >= range) {
        k += 3 * range * range;
        findBoard(n - 1, r - range, c - range);
    } else if (c >= range) {
        k += range * range;
        findBoard(n - 1, r, c - range);
    } else if (r >= range) {
        k += range * range * 2;
        findBoard(n - 1, r - range, c);
    } else {
        findBoard(n-1,r,c);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R >> C;
    findBoard(N, R, C);
    cout << k;
}
