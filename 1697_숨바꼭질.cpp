//
// Created by 이승철 on 2022/08/30.
//
#include <iostream>
#include <queue>

using namespace std;
int n, k;
int dir[100005];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dir, dir + 100005, -1);

    dir[n] = 0;
    Q.push(n);

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if(cur == k)
            break;

        for (int nr: {cur - 1, cur + 1, 2 * cur}) {

            if(nr < 0 || nr >= 100005)
                continue;

            if (dir[nr] > -1)
                continue;

            dir[nr] = dir[cur] + 1;
            Q.push(nr);
        }
    }

    cout << dir[k];
}

