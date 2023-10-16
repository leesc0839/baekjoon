//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
ll N, M;
ll two, five;

pair<ll, ll> findSquare(ll k) { // n/2 + n/4 + n/8 + n/16  … 나눈 값이 n 보다 크면 stop 5도 마찬가지
    ll squ_two = 2;
    ll squ_five = 5;
    ll two_cnt = 0;
    ll five_cnt = 0;

    while (k >= squ_two) {
        two_cnt += k / squ_two;
        squ_two *= 2;
    }

    while (k >= squ_five) {
        five_cnt += k / squ_five;
        squ_five *= 5;
    }
    return {two_cnt, five_cnt};
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    auto NFac = findSquare(N);
    two += NFac.first;
    five += NFac.second;

    auto MFac = findSquare(M);
    two -= MFac.first;
    five -= MFac.second;

    auto nMinusMFac = findSquare(N - M);
    two -= nMinusMFac.first;
    five -= nMinusMFac.second;

    cout << min(two, five);
}
