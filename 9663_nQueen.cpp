//
// Created by 이승철 on 2022/08/03.
//
#include <iostream>
#include <vector>

using namespace std;
int N, cnt, q_cnt;
vector<int> v[16];

bool isAvailable(int r, int c) {

    for (int i = 1; i <= N; i++) {
        if (v[i].empty())
            continue;
        if (v[i][0] == c) // c가 같을 때
            return false;
        if (r - i == c - v[i][0]) // 대각선
            return false;
        if (r - i == v[i][0] - c) // 대각선
            return false;
    }
    return true;
}

void dfs(int r) {
    if (q_cnt == N) { // base condition
        cnt++;
        return;
    }

    for (int c = 1; c <= N; c++) { // C
        if (isAvailable(r, c)) {
            v[r].emplace_back(c);
            q_cnt++;
            dfs(r + 1);
            v[r].clear();
            q_cnt--;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dfs(1);
    cout << cnt;
}