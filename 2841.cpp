//
// Created by 이승철 on 2022/07/11.
//
#include <iostream>
#include <queue>

using namespace std;
int cnt;


int main() {

    int line, p;
    int N, P;

    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq[7];
    cin >> N >> P;
    while (N--) {
        cin >> line >> p;
        if (pq[line].empty()) {
            cnt++;
            pq[line].push(p);
        } else if (pq[line].top() < p) {
            cnt++;
            pq[line].push(p);
        } else {
            while (pq[line].top() > p) {
                if (pq[line].empty()) {
                    break;
                }
                cnt++;
                pq[line].pop();
            }
            if (pq[line].empty()) {
                pq[line].push(p);
                cnt++;
            }
            if (pq[line].top() < p) {
                pq[line].push(p);
                cnt++;
            }
        }
    }
    cout << cnt;

}
