#include <iostream>
using namespace std;
using ll = long long;
ll A, B, C;

ll recursion(ll a, ll b, ll c) {
    if (b == 1) // base condition
        return a % c;

    // base condition에 수렴하도록 재귀함수 설계
    // k일 때
    ll tmp = recursion(a, b / 2, c);

    // 2k
    tmp = tmp * tmp % c;
    if (b % 2 == 0)
        return tmp;
    // 2k + 1
    else
        return (tmp * a) % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C;
    cout << recursion(A, B, C);
}

