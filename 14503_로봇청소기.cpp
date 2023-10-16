//
// Created by 이승철 on 2022/10/04.
//
#include <iostream>

#define MAX 51
using namespace std;
int map[MAX][MAX], R, C, cur_r, cur_c, cur_dir, ans;
int dr[4] = {-1, 0, 1, 0}; //북  서 남 동
int dc[4] = {0, -1, 0, 1};
bool visit[MAX][MAX];

void dfs(int cr, int cc, int cd) {

    for (int i = cd + 1; i < cd + 5; i++) {
        int nxt_r = cr + dr[i % 4];
        int nxt_c = cc + dc[i % 4];

        if (nxt_r < 0 || nxt_r >= R || nxt_c < 0 || nxt_c >= C)
            continue;
        if (visit[nxt_r][nxt_c] || map[nxt_r][nxt_c] == 1)
            continue;
        visit[nxt_r][nxt_c] = true;
        ans++;
        dfs(nxt_r, nxt_c, i % 4);
    }
    
    int nxt_r = cr - dr[cd];
    int nxt_c = cc - dc[cd];
    if (nxt_r < 0 || nxt_r >= R || nxt_c < 0 || nxt_c >= C) {
        cout << ans;
        exit(0);
    }

    if (map[nxt_r][nxt_c] == 1) {
        cout << ans;
        exit(0);
    }
    if (!visit[nxt_r][nxt_c]) {
        visit[nxt_r][nxt_c] = true;
        ans++;
    }
    dfs(nxt_r, nxt_c, cd % 4);
}

void input() {
    cin >> R >> C;
    cin >> cur_r >> cur_c >> cur_dir;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> map[i][j];
    }
}

void sol() {
    if (cur_dir == 1)  // 동
        cur_dir = 3;
    else if (cur_dir == 3)  // 서
        cur_dir = 1;

    visit[cur_r][cur_c] = true;
    ans++;
    dfs(cur_r, cur_c, cur_dir);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}


