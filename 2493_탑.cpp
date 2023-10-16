//
// Created by 이승철 on 2022/07/25.
//
#include <iostream>
#include <stack>

#define idx first
#define height second
using namespace std;
int returnArr[500001], n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<pair<int, int>> s1;
    stack<pair<int, int>> s2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        s1.push({i, h});
    }
    s2.push(s1.top());
    s1.pop();
    while (!s1.empty()) {
        if (!s2.empty() && s1.top().height > s2.top().height) {
            while (!s2.empty() && s1.top().height > s2.top().height) {
                returnArr[s2.top().idx] = s1.top().idx;
                s2.pop();
            }
            s2.push(s1.top());
            s1.pop();
        } else {
            returnArr[s2.top().idx] = 0;
            s2.push(s1.top());
            s1.pop();
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << returnArr[i] << " ";
    }

}
