//
// Created by 이승철 on 2022/08/04.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int board[21][21];
int N;
int returnValue = 50000;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < N / 2; i++)
        v.emplace_back(0);
    for (int i = 0; i < N / 2; i++)
        v.emplace_back(1);

    do {
        int a = 0;
        int b = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (v[i] != v[j])
                    continue;
                if (v[i] == 0)
                    a += board[i][j] + board[j][i];
                else if (v[i] == 1)
                    b += board[i][j] + board[j][i];
            }
        }
        returnValue = min(returnValue, b - a < 0 ? -1 * (b - a) : b - a);
    } while (next_permutation(v.begin(), v.end()));
    cout<<returnValue;
}
