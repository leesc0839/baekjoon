//
// Created by 이승철 on 2022/08/04.
//
#include <iostream>
#include <vector>

#define K 6
using namespace std;
int N;
int output_arr[6];
bool isUsed[13];
vector<int> v;

void dfs(int cnt) {
    if (cnt == K) {
        for (int i: output_arr)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!isUsed[i]) {
            if (cnt > 0 && output_arr[cnt - 1] > v[i])
                continue;
            output_arr[cnt] = v[i];
            isUsed[i] = true;
            dfs(cnt + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> N;
        if (N == 0)
            break;

        v.resize(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];

        dfs(0);
        cout << '\n';
        v.clear();
        fill(isUsed, isUsed + 13, false);
    }

}
