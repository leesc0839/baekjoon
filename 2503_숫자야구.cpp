//
// Created by 이승철 on 2022/08/05.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, elem, strike, ball;
bool isPossible[1000];

int checkStrike(int e, int cur) {
    int rtn = 0;
    while (true) {
        if (e == 0)
            break;
        if (e % 10 == cur % 10)
            rtn++;
        e /= 10;
        cur /= 10;
    }
    return rtn;
}

int checkBall(int e, int cur) {
    vector<int> v;
    v.resize(3);
    int rtn = 0;
    for (int i = 1; i <= 3; i++) {
        v[3 - i] = e % 10;
        e /= 10;
    }

    while (true) {
        if (cur == 0)
            break;
        if (binary_search(v.begin(), v.end(), cur % 10))
            rtn++;
        cur /= 10;
    }
    return rtn;
}

void check(int e, int s, int b) {
    for (int i = 100; i < 1000; i++) {
        if (checkStrike(e, i) == s && checkBall(e, i) >= b && isPossible[i])
            isPossible[i] = true;
        else
            isPossible[i] = false;
    }
}

void firstCheck(int e, int s, int b) {
    for (int i = 100; i < 1000; i++) {
        if (checkStrike(e, i) == s && checkBall(e, i) >= b)
            isPossible[i] = true;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> elem >> strike >> ball;
        if (i == 0)  // 초기 설정
            firstCheck(elem, strike, ball);
        else
            check(elem, strike, ball);
    }
    int rtn = 0;
    for (int i = 100; i < 1000; i++) {
        if (isPossible[i]){
            int a = i % 10;
            int b = (i / 10) % 10;
            int c = (i / 100) % 10;
            if (a != b && b != c && c != a)
                rtn++;
        }
    }
    cout << rtn;
}

