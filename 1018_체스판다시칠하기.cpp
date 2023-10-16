//
// Created by 이승철 on 2022/09/25.
//
#include <iostream>
#include <algorithm>

#define MAX 51
using namespace std;
int R, C, ans = 64;
char map[MAX][MAX];
char black_start[8] = {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};
char white_start[8] = {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> map[i][j];
    }
}

void count_min(int r, int c) {
    int black_start_cnt = 0;
    int cnt = 0;
    for (int i = r; i < r + 8; i++) {
        if (cnt % 2 == 0) {
            for (int j = 0; j < 8; j++) {
                if (black_start[j] != map[i][c + j])
                    black_start_cnt++;
            }
        } else if (cnt % 2 == 1) {
            for (int j = 0; j < 8; j++) {
                if (white_start[j] != map[i][c + j])
                    black_start_cnt++;
            }
        }
        cnt++;
    }

    int white_start_cnt = 0;
    int cnt2 = 0;
    for (int i = r; i < r + 8; i++) {
        if (cnt2 % 2 == 0) {
            for (int j = 0; j < 8; j++) {
                if (white_start[j] != map[i][c + j])
                    white_start_cnt++;
            }
        } else if (cnt2 % 2 == 1) {
            for (int j = 0; j < 8; j++) {
                if (black_start[j] != map[i][c + j])
                    white_start_cnt++;
            }
        }
        cnt2++;
    }
    ans = min(ans, min(black_start_cnt, white_start_cnt));
}

void sol() {
    for (int i = 0; i <= R - 8; i++) {
        for (int j = 0; j <= C - 8; j++)
            count_min(i, j);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
