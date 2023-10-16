//
// Created by 이승철 on 2022/12/24.
//
#include <iostream>
#include <set>

using namespace std;
int N, ans;


void sol() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        set<char> alpha;
        bool isPossible = true;
        string s;
        cin >> s;
        char pre = '.';
        for (auto cur: s) {
            if (pre != cur && alpha.count(cur)){
                isPossible = false;
                break;
            }
            alpha.insert(cur);
            pre = cur;
        }
        if (isPossible)
            ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}

