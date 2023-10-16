//
// Created by 이승철 on 2022/08/17.
//
#include <iostream>
#include <algorithm>

using namespace std;
int board[1005][1005];
int dc[3] = {-1, 0, 1};
int r, c, curC, min_length = 1000001;
int p_direction[1005][1005];
int dp[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cin >> board[i][j];
    }
    fill(p_direction[0], p_direction[0] + 1005, 4);
    for (int i = 0; i < c; i++)
        dp[1][i] += board[1][i];// 2행부터 위에 체크 하면서 보기

    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int m = 101;
            int d;
            for (int dir = 0; dir < 3; dir++) {
                int prevC = j + dc[dir];
                if (prevC < 0 && prevC >= c)
                    continue;
                if (p_direction[i - 1][prevC] == dir)
                    continue;
                if (m > board[i - 1][prevC]) {
                    m = board[i - 1][prevC];
                    d = dir;
                }
            }
            p_direction[i][j] = d;
            board[i][j] += m;
            cout << board[i][j] <<' ';
        }
        cout <<'\n';
    }
}

