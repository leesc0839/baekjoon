//
// Created by 이승철 on 2022/08/05.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int L, N;
bool is_m;
vector<string> v;
vector<string> output_v;
bool isUsed[20];

void dfs(int cur) {
    if (L == cur) {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (i == j)
                    continue;
                if (output_v[i][j] != output_v[j][i])
                    return;
            }
        }
        is_m = true;
        for (int i = 0; i < L; i++)
            cout << output_v[i] << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            output_v.emplace_back(v[i]);

            dfs(cur + 1);
            if (is_m)
                return;
            isUsed[i] = false;
            output_v.erase(--output_v.end());
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    std::sort(v.begin(), v.end());
    dfs(0);

    if (!is_m)
        cout << "NONE";
}

