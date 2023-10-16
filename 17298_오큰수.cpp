//
// Created by 이승철 on 2022/07/24.
//
#include <iostream>
#include <stack>

using namespace std;
int returnArr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S1;
    stack<int> S2;
    int stackSize;
    cin >> stackSize;
    for (int i = 0; i < stackSize; i++) {
        int s;
        cin >> s;
        S1.push(s);
    }
    S2.push(S1.top());
    S1.pop();
    returnArr[S1.size()] = -1;

    while (!S1.empty()) {
        int t = S1.top();
        S1.pop();
        while (!S2.empty() && t >= S2.top()) // 비어 있는 상태 에서 top에 접근 하면 안된다.
            S2.pop();
        returnArr[S1.size()] = S2.empty() ? -1 : S2.top();
        S2.push(t);
    }
    for (int i = 0; i < stackSize; i++)
        cout << returnArr[i] << " ";
}

