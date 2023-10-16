//
// Created by 이승철 on 2022/12/24.
//
#include <iostream>
#include <queue>

using namespace std;
int N, k;
priority_queue<int, vector<int>, greater<>> pq;

void input() {
    cin >> N;
    while (N--) {
        cin >> k;
        pq.push(k);
    }
}

void sol() {
    while (!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
