//
// Created by 이승철 on 2023/03/19.
//
#include <iostream>

using namespace std;
const int MX = 9;
int map[MX][MX];
int row[MX], column[MX], box[MX];

int box_idx(int r, int c) {
    return 3 * (r / 3) + (c / 3);
}

void input() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> map[r][c];

            row[r] += (1 << (map[r][c] - 1));
            column[c] += (1 << (map[r][c] - 1));
            box[box_idx(r, c)] += (1 << (map[r][c] - 1));
        }
    }
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
}

void fun(int r, int c) {
    if (r == 9 && c == 0) {
        for (int i = 0; i < 8; i++) {
            if (!(row[i] & (1 << 9) - 1))
                return;
            if (!(column[i] & (1 << 9) - 1))
                return;
            if (!(box[i] & (1 << 9) - 1))
                return;
        }
        print();
        exit(0);
    }
    if (map[r][c] != 0) {
        (c == 8) ? fun(r + 1, 0) : fun(r, c + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (row[r] & (1 << (i - 1)))
            continue;
        if (column[c] & (1 << (i - 1)))
            continue;
        if (box[box_idx(r, c)] & (1 << (i - 1)))
            continue;

        map[r][c] = i;
        row[r] += (1 << (map[r][c] - 1));
        column[c] += (1 << (map[r][c] - 1));
        box[box_idx(r, c)] += (1 << (map[r][c] - 1));

        (c == 8) ? fun(r + 1, 0) : fun(r, c + 1);

        row[r] -= (1 << (map[r][c] - 1));
        column[c] -= (1 << (map[r][c] - 1));
        box[box_idx(r, c)] -= (1 << (map[r][c] - 1));
        map[r][c] = 0;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    fun(0, 0);


}
