#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, less<>> left_pq;
priority_queue<int, vector<int>, greater<>> right_pq;

using namespace std;
int n, k;

void push(bool is_odd, int k) {
    if (is_odd) {
        if (right_pq.empty()) {
            left_pq.push(k);
            cout << k << '\n';
            return;
        }
        if (right_pq.top() < k) {
            left_pq.push(right_pq.top());
            right_pq.pop();
            right_pq.push(k);
        } else
            left_pq.push(k);
        cout << left_pq.top() << '\n';
    } else {
        if (left_pq.top() > k) {
            right_pq.push(left_pq.top());
            left_pq.pop();
            left_pq.push(k);
        } else
            right_pq.push(k);
        cout << min(left_pq.top(), right_pq.top()) << '\n';
    }
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        push(i % 2, k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}