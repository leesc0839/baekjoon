//
// Created by 이승철 on 2023/03/20.
//
#include <iostream>
#include <stack>

using namespace std;

int N, K;
string num;
stack<int> s, ans;

void input() {
    cin >> N >> K;
    cin >> num;
}

void fun() {
    int k = 0;
    for (char c: num) {
        while (!s.empty() && k < K && c > s.top()) {
            k++;
            s.pop();
        }
        s.push(c);
    }
    while (k < K) {
        k++;
        s.pop();
    }
}

void sol() {
    fun();
    while (!s.empty()) {
        ans.push(s.top());
        s.pop();
    }
    while (!ans.empty()) {
        cout << ans.top() - '0';
        ans.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
