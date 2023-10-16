//
// Created by 이승철 on 2023/09/17.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MX = 1029;
int n, board[MX][MX];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
}

int sol(int size, int r, int c) {
    if (size == 1)
        return board[r][c];

    vector<int> v;
    int n_size = size / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            v.emplace_back(sol(n_size, r + i * n_size, c + j * n_size));
    sort(v.begin(), v.end());
    return v[1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << sol(n, 0, 0);
}