//
// Created by 이승철 on 2022/08/01.
//
#include <iostream>
#include <cmath>
#include <set>

using namespace std;
bool isPrime[10000];
bool visit[10000];
int TK, start, dest;
set<int> S;

void findPrime() {
    fill(isPrime, isPrime + 10000, true);
    for (int i = 2; i <= 100; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < 10000; j += i)
                isPrime[j] = false;
        }
    }
}

void dp(int elem, int cnt, int digit, int idx) {
    if (elem == dest) {
        S.emplace(cnt);
        return;
    }

    visit[elem] = true;
    if (idx == 10)
        digit += 1;

    int tmp = elem;
    for (int k = 0; k < digit; k++)
        tmp /= 10;

    int nxt = elem - ((tmp % 10) * (int) pow(10, digit));
    for (int i = 0; i < idx; i++)
        nxt += (int) pow(10, digit);

    if (nxt < 1000)
        nxt += 1000;

    visit[nxt] = true;
    dp(nxt, cnt + 1, digit, idx + 1);
    visit[nxt] = false;






}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    findPrime();
    isPrime[0] = isPrime[1] = false;
    cin >> TK;
    while (TK--) {
        cin >> start >> dest;
        dp(start, 0, 0, 0);

        if (S.empty())
            cout << "Impossible\n";
        else
            cout << *S.begin() << '\n';

        fill(visit, visit + 10000, false);
        S.clear();
    }
}
