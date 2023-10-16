//
// Created by 이승철 on 2022/07/25.
//
#include <iostream>
#include <stack>

using namespace std;
int N;
int appear[1000001];
int returnArr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    stack<int> S1;
    stack<int> S2;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        appear[k]++;
        S1.push(k);
    }
    while (!S1.empty()) {
        auto cur = S1.top();
        S1.pop();

        while (!S2.empty() && appear[cur] >= appear[S2.top()])
            S2.pop();

        if (S2.empty()) {
            returnArr[S1.size()] = -1;
            S2.push(cur);
        } else {
            returnArr[S1.size()] = S2.top();
            S2.push(cur);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << returnArr[i] <<" ";
    }
}
