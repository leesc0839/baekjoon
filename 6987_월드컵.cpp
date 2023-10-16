#include <iostream>

using namespace std;
int board[6][3];
int myBoard[6][3];
bool isPossible;

bool checkBoard() {
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] != myBoard[r][c])
                return false;
        }
    }
    return true;
}

void func(int i, int j) {
    if (i == 4 && j == 5) {
        if (checkBoard())
            isPossible = true;
        return;
    }

    for (int c = 0; c < 3; c++) { // 0 win 1 draw 2 lose
        myBoard[i][c]++;
        myBoard[j][2 - c]++;

        if (j >= 5) {
            i += 1;
            j = i;
        }
        cout << i << ' ' << j + 1 << '\n';
        func(i, j + 1);
        myBoard[i][c]--;
        myBoard[j][2 - c]--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 3; c++)
                cin >> board[r][c];
        }
        func(0, 1);
        if (isPossible)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
        isPossible = false;
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 3; c++)
                myBoard[i][c] = 0;
        }
    }
}