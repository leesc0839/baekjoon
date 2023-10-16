//
// Created by 이승철 on 2022/08/09.
//
#include <iostream>

using namespace std;
int board[7][4];
bool isPossible;

void func(int i, int j) { // i, j 는 나라
    if (i == 6) { // 5 ,6 일 때 마지막 경우 체크 한 후를 base condition으로
        for (int r = 1; r <= 6; r++) {
            for (int c = 1; c <= 3; c++) {
                if (board[r][c] != 0)
                    return;
            }
        }
        isPossible = true;
        return;
    }

    for (int c = 1; c <= 3; c++) {
        if (board[i][c] && board[j][4 - c]) {
            board[i][c]--;
            board[j][4 - c]--;

            if (j == 6)
                func(i + 1, i + 2);
            else
                func(i, j + 1);

            board[i][c]++;
            board[j][4 - c]++;

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int r = 1; r <= 6; r++) {
            for (int c = 1; c <= 3; c++)
                cin >> board[r][c];
        }

        func(1, 2);
        if (isPossible)
            cout << "1 ";
        else
            cout << "0 ";
        isPossible = false;
    }
}

