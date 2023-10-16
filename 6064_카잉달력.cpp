//
// Created by 이승철 on 2022/07/28.
//
#include <iostream>

using namespace std;
int m, n, x, y;
bool isExist;

// 수학 부분 인터넷 강의를 듣다가 아이디어 를 얻고, 접근 하였습니다.

int gcd(int a, int b) { // 최대 공약수
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        x--;
        y--;
        int lcm = m * n / gcd(m, n);

/* m, n 의 최대 공약수 즉, 0부터 마지막 해까지 적절한 해인지 비교를 한다면, lcm(마지막 해) 은 m*n 이다.
 * 따라서 O(m * n) => 시간 초과
 * x에 적절한 값에서 y를 확인 해주는 방식 으로 가면,
 * m * n / m => 즉 O(n)으로 시간 내에 처리가 가능 하다.
*/
        for (int i = x; i < lcm; i += m) {
            if (i % n == y) {
                isExist = true;
                cout << i + 1 << '\n';
                break;
            }
        }
        if (!isExist)
            cout << -1 << '\n';
        isExist = false;
    }
}
