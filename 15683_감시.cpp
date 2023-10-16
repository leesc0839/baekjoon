//
// Created by 이승철 on 2022/09/22.
//
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 9
using namespace std;
int R, C, ans = MAX * MAX, map[MAX][MAX], elem, cctv_idx;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int selected[8], arr[8];
bool is_catch[MAX][MAX];
bool is_cctv_catch[MAX][MAX][8][4]; // ~번 cctv가 ~방향으로 볼 수 있는 곳
vector<pair<int, int>> cctv[6];

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> elem;
            map[i][j] = elem;
            if (0 < elem && elem < 6)
                cctv[elem].emplace_back(i, j);
        }
    }
}

void check_tool(int cctv_idx, int dir_idx, int r, int c, int dir) {
    while (true) {
        r += dr[dir];
        c += dc[dir];

        if (r < 0 || r >= R || c < 0 || c >= C || map[r][c] == 6)
            return;
        is_cctv_catch[r][c][cctv_idx][dir_idx] = true;
    }
}

void check(int cctv_num, int cctv_idx, int dir_idx, int r, int c, int dir) {

    is_cctv_catch[r][c][cctv_idx][dir_idx] = true;

    if (cctv_num == 1) {
        check_tool(cctv_idx, dir_idx, r, c, dir);
        return;
    }

    if (cctv_num == 2) {
        if (dir % 2 == 0) {
            check_tool(cctv_idx, dir_idx, r, c, 0);
            check_tool(cctv_idx, dir_idx, r, c, 2);
        } else {
            check_tool(cctv_idx, dir_idx, r, c, 1);
            check_tool(cctv_idx, dir_idx, r, c, 3);
        }
        return;
    }

    if (cctv_num == 3) {
        check_tool(cctv_idx, dir_idx, r, c, dir % 4);
        check_tool(cctv_idx, dir_idx, r, c, (dir + 1) % 4);
        return;
    }

    if (cctv_num == 4) {
        check_tool(cctv_idx, dir_idx, r, c, dir % 4);
        check_tool(cctv_idx, dir_idx, r, c, (dir + 1) % 4);
        check_tool(cctv_idx, dir_idx, r, c, (dir + 2) % 4);
        return;
    }

    if (cctv_num == 5) {
        for (int i = 0; i < 4; i++)
            check_tool(cctv_idx, dir_idx, r, c, i);
        return;
    }
}

void check_catch() {
    for (int i = 0; i < cctv_idx; i++) {
        int dir = selected[i];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (is_cctv_catch[r][c][i][dir])
                    is_catch[r][c] = true;
            }
        }
    }
}

void count_blind() {
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (is_catch[i][j] || map[i][j] == 6)
                cnt++;
            is_catch[i][j] = false;
        }
    }
    ans = min(R * C - cnt, ans);
}

void pi(int cnt) {
    if (cnt == cctv_idx) {
        check_catch();
        count_blind();
        return;
    }
    for (int i = 0; i < 4; i++) {
        selected[cnt] = arr[i];
        pi(cnt + 1);
    }
}

void sol() {
    for (int i = 1; i <= 5; i++) {
        for (auto cur: cctv[i]) {
            int cur_r = cur.first;
            int cur_c = cur.second;
            for (int dir = 0; dir < 4; dir++)
                check(i, cctv_idx, dir, cur_r, cur_c, dir);
            cctv_idx++;
        }
    }

    for (int i = 0; i < 4; i++)
        arr[i] = i;
    pi(0);
    cout << ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();

}

