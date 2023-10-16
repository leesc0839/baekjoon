//
// Created by 이승철 on 2022/09/30.
//
#include <iostream>

#define MAX 21
#define E 1
#define W 2
#define N 3
#define S 4
#define B 5
#define T 6

using namespace std;
int R, C, X, Y, K, direction, map[MAX][MAX];
int dr[5] = {-1, 0, 0, -1, 1};
int dc[5] = {-1, 1, -1, 0, 0};
pair<int, int> cur_location;
int dice[7]; // 0. tmp, 1. 동, 2. 서, 3. 북, 4. 남, 5, bottom, 6. top
int dice_copy[7];

void east() {
    dice_copy[B] = dice[E];
    dice_copy[T] = dice[W];
    dice_copy[S] = dice[S];
    dice_copy[N] = dice[N];
    dice_copy[W] = dice[B];
    dice_copy[E] = dice[T];
}

void west() {
    dice_copy[T] = dice[E];
    dice_copy[B] = dice[W];
    dice_copy[S] = dice[S];
    dice_copy[N] = dice[N];
    dice_copy[E] = dice[B];
    dice_copy[W] = dice[T];
}

void north() {
    dice_copy[E] = dice[E];
    dice_copy[S] = dice[S];
    dice_copy[T] = dice[S];
    dice_copy[B] = dice[N];
    dice_copy[S] = dice[B];
    dice_copy[N] = dice[T];
}

void south() {
    dice_copy[E] = dice[E];
    dice_copy[S] = dice[S];
    dice_copy[B] = dice[S];
    dice_copy[T] = dice[N];
    dice_copy[N] = dice[B];
    dice_copy[S] = dice[T];
}

bool change_location(int dir) {
    pair<int, int> nxt_location = {cur_location.first + dr[dir], cur_location.second + dc[dir]};
    if (nxt_location.first < 0 || nxt_location.first >= R || nxt_location.second < 0 || nxt_location.second >= C)
        return false;
    cur_location = nxt_location;
    return true;
}

void roll_dice(int dir) {
    if (!change_location(dir))
        return;
    if (dir == 1)
        east();
    else if (dir == 2)
        west();
    else if (dir == 3)
        north();
    else if (dir == 4)
        south();

    for (int i = 1; i <= 6; i++)
        dice[i] = dice_copy[i];

    if (map[cur_location.first][cur_location.second] == 0)
        map[cur_location.first][cur_location.second] = dice[B];
    else {
        dice[B] = map[cur_location.first][cur_location.second];
        map[cur_location.first][cur_location.second] = 0;
    }
    cout << dice[T] << '\n';
}

void sol() {
    cin >> R >> C >> X >> Y >> K;
    cur_location = {X, Y};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> map[i][j];
    }
    for (int i = 0; i < K; i++) {
        cin >> direction;
        roll_dice(direction);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();

}