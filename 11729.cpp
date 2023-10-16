#include <iostream>

using namespace std;
int N;
int cnt;

void recursion(int a, int b, int n) {
    if (n == 1) // base condition
        cout << a << ' ' << b << '\n';
    recursion(a, 6 - a - b, n - 1); // n-1개 원판을 a -> 6-a-b로
    cout << a << ' ' << b << '\n'; // n번 원판을 a,b로 옮긴다.
    recursion(6 - a - b, b, n - 1); // n-1개를 6 - a- b에서 b로 옮긴다.
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;


}