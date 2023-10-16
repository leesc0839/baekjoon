//
// Created by 이승철 on 2022/12/19.
//
#include <iostream>
#include <queue>

using namespace std;
int N, M, e;
queue<int> A, B;
queue<int> Q;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> e;
        A.push(e);
    }
    for (int i = 0; i < M; i++) {
        cin >> e;
        B.push(e);
    }
}

void sol() {
    for (int i = 0; i < N + M; i++) {
        if (A.empty()) {
            Q.push(B.front());
            B.pop();
            continue;
        }
        if (B.empty()) {
            Q.push(A.front());
            A.pop();
            continue;
        }
        if (A.front() < B.front()) {
            Q.push(A.front());
            A.pop();
        } else {
            Q.push(B.front());
            B.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
    while (!Q.empty()) {
        cout << Q.front() << ' ';
        Q.pop();
    }
}
