//
// Created by 이승철 on 2023/09/21.
//
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int N;
string str;
set<pair<int, string>> s;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.insert({str.size(), str});
    }
}

void sol() {
    for (auto cur: s)
        cout << cur.second << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();
}

