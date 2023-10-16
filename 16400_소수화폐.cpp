//
// Created by 이승철 on 2022/08/01.
//
#include <iostream>

using namespace std;
bool isPrime[40001];
bool visit[40001];
int N;
int cnt;

void findPrime() {
    fill(isPrime, isPrime + 40001, true);
    for (int i = 2; i <= 201; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < 40001; j += i)
                isPrime[j] = false;
        }
    }
}

void dp(int remain_money, int cur) {
    if (remain_money == 0) {
        cnt++;
        return;
    }
    if (remain_money == 1)
        return;


    while (!isPrime[cur] && !visit[cur])
        --cur;

    visit[cur] = true;
    remain_money %= cur;
    dp(remain_money, cur);
    visit[cur] = false;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    findPrime();
    isPrime[0] = isPrime[1] = false;
    cin >> N;
    dp(N, N);
    cout << cnt;

}
