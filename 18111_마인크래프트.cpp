//
// Created by 이승철 on 2022/08/05.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, M, B, max_h;
int min_h = 256;
int board[501][501];
map<int, int> rtn_map;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            max_h = max(max_h, board[i][j]);
            min_h = min(min_h, board[i][j]);
        }
    }

    for (int i = min_h; i <= max_h; i++) {
        int b = B;
        int t = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (board[j][k] == i)
                    continue;
                else if (board[j][k] > i) {
                    t += 2 * (board[j][k] - i);
                    b += (board[j][k] - i);
                } else {
                    t += i - board[j][k];
                    b -= i - board[j][k];
                }
            }
        }
        if (b >= 0) {
            if (rtn_map.count(t) && rtn_map.find(t)->second < i)
                rtn_map.find(t)->second = i;
            else
                rtn_map.emplace(t, i);
        }
    }

    cout << rtn_map.begin()->first << " " << rtn_map.begin()->second;
}
