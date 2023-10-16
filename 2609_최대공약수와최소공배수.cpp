//
// Created by 이승철 on 2022/07/27.
//
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, key, mid;
    cin >> N;
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, less<>> right;

    cin >> key;
    cout << key << '\n';
    left.push(key);
    mid = key;

    for (int i = 1; i < N; i++) {
        cin >> key;
        (key > mid) ? right.push(key) : left.push(key);

        if (i % 2)  // 데이터 개수가 홀수
            left.size() > right.size() ? mid = left.top() : mid = right.top();
        else  // 데이터 개수가 짝수
            left.top() < right.top() ? mid = left.top() : mid = right.top();

        cout << mid;
    }

}
