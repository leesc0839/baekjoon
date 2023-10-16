//
// Created by 이승철 on 2023/02/27.
//
#include <iostream>
#include <queue>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

struct info {
    int r;
    int c;
    int pre_dir;
};

using namespace std;
int R, C, block_cnt;
int missing_r, missing_c, missing_dir;
const int MX = 26;
char map[MX][MX];
char block[7] = {'|', '-', '+', '1', '2', '3', '4'};
queue<info> Q;
int dr[4] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dc[4] = {0, 1, 0, -1};

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'M')
                Q.push({i, j, -1});
            else if (map[i][j] != '.' && map[i][j] != 'M' && map[i][j] != 'Z')
                block_cnt++;
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return true;
    return false;
}

void find_starting_point() {
    auto cur = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
        int nr = cur.r + dr[i];
        int nc = cur.c + dc[i];

        if (OOB(nr, nc))
            continue;
        if (map[nr][nc] != '.' && map[nr][nc] != 'Z') {
            Q.push({nr, nc, i});
            return;
        }
    }
}

int find_nxt_dir(int cur_r, int cur_c, int prev_dir) {
    if (map[cur_r][cur_c] == '|') {
        if (prev_dir == SOUTH)
            return SOUTH;
        else if (prev_dir == NORTH)
            return NORTH;
    } else if (map[cur_r][cur_c] == '-') {
        if (prev_dir == WEST)
            return WEST;
        else if (prev_dir == EAST)
            return EAST;
    } else if (map[cur_r][cur_c] == '+') {
        return prev_dir;
    } else if (map[cur_r][cur_c] == '1') {
        if (prev_dir == WEST)
            return SOUTH;
        else if (prev_dir == NORTH)
            return EAST;
    } else if (map[cur_r][cur_c] == '2') {
        if (prev_dir == SOUTH)
            return EAST;
        else if (prev_dir == WEST)
            return NORTH;
    } else if (map[cur_r][cur_c] == '3') {
        if (prev_dir == EAST)
            return NORTH;
        else if (prev_dir == SOUTH)
            return WEST;
    } else if (map[cur_r][cur_c] == '4') {
        if (prev_dir == EAST)
            return SOUTH;
        else if (prev_dir == NORTH)
            return WEST;
    }
    return -1;
}

void find_missing_position() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        int nxt_dir = find_nxt_dir(cur.r, cur.c, cur.pre_dir);
        int nr = cur.r + dr[nxt_dir];
        int nc = cur.c + dc[nxt_dir];

        if (map[nr][nc] == '.') {
            missing_r = nr;
            missing_c = nc;
            missing_dir = nxt_dir;
            return;
        }
        Q.push({nr, nc, nxt_dir});
    }
}

void find_z() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        int nxt_dir = find_nxt_dir(cur.r, cur.c, cur.pre_dir);
        if (nxt_dir == -1)
            return;
        int nr = cur.r + dr[nxt_dir];
        int nc = cur.c + dc[nxt_dir];
        if (OOB(nr, nc))
            continue;
        if (map[nr][nc] == 'Z') {
            cout << missing_r + 1 << ' ' << missing_c + 1 << ' ' << map[missing_r][missing_c];
            exit(0);
        }
        Q.push({nr, nc, nxt_dir});
    }
}

void find_block() {
    for (char i: block) {
        Q = queue<info>();
        map[missing_r][missing_c] = i;
        Q.push({missing_r, missing_c, missing_dir});
        find_z();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    find_starting_point();
    find_missing_position();
    find_block();
}
