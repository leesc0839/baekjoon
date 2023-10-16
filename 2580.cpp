//
// Created by 이승철 on 2022/07/11.
//
#include <iostream>

using namespace std;

int board[10][10];
int k, cnt, sum, zeroR, zeroC;
int dr[9] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
int dc[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> k;
            sum += k;
            if (k == 0) {
                cnt++;
                zeroR = i;
                zeroC = j;
            }
            board[i][j] = k;
        }
        if (cnt == 1)
            board[zeroR][zeroC] = 45 - sum;
        zeroR = zeroC = sum = cnt = 0;
    }

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (board[j][i] == 0) {
                zeroR = j;
                zeroC = i;
                cnt++;
            }
            sum += board[j][i];
        }
        if (cnt == 1)
            board[zeroR][zeroC] = 45 - sum;
        zeroR = zeroC = sum = cnt = 0;
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if ((i % 3 == 2) && (j % 3 == 2)) {
                for (int c = 0; c < 9; c++) {
                    sum += board[i + dr[c]][j + dc[c]];
                    if (board[i + dr[c]][j + dc[c]] == 0) {
                        zeroR = i + dr[c];
                        zeroC = j + dc[c];
                        cnt ++;
                    }
                }
                if (sum < 45 && cnt ==1)
                    board[zeroR][zeroC] = 45 - sum;
            }
            sum = 0;
            cnt = 0;
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++)
            cout << board[i][j] << " ";
        cout << '\n';
    }

}