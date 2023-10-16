//
// Created by 이승철 on 2023/03/19.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, S, T;
vector<pair<int, int>> lec;
priority_queue<int, vector<int>, greater<>> pq;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        lec.emplace_back(S, T);
    }
    sort(lec.begin(), lec.end());
}

void sol() {
    pq.push(lec[0].second);
    for (int idx = 1; idx < N; idx++) {
        int cur_end = pq.top();
        int nxt_start = lec[idx].first;
        int nxt_end = lec[idx].second;

        if (nxt_start < cur_end)
            pq.push(nxt_end);
        else {
            pq.pop();
            pq.push(nxt_end);
        }
    }
    cout << pq.size();
}

int main() {
    ios::sync_with_stdio(0);
    input();
    sol();

}