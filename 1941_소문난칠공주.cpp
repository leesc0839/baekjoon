//
// Created by 이승철 on 2022/11/03.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
char map[5][5];
int check_map[5][5];
pair<int, int> idx[25];
set<pair<pair<int, int>, char>> girls;
vector<int> arr;
queue<pair<int, int>> Q;
int ans;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];
    }
}

void init() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            idx[i * 5 + j] = {i, j};
    }

    for (int i = 0; i < 25; i++)
        (i < 7) ? arr.push_back(0) : arr.push_back(1);
}

bool bfs() {
    int cnt = 1;
    check_map[girls.begin()->first.first][girls.begin()->first.second] = 1;
    Q.push({girls.begin()->first.first, girls.begin()->first.second});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)
                continue;
            if (check_map[nr][nc] != 0)
                continue;
            check_map[nr][nc] = 1;
            Q.push({nr, nc});
            cnt++;
        }
    }
    return (cnt == 7);

}

bool is_all_near() {
    for (int i = 0; i < 5; i++)
        fill(check_map[i], check_map[i] + 5, -1);
    for (auto cur: girls)
        check_map[cur.first.first][cur.first.second] = 0;
    return bfs();
}

void sol() {
    do {
        girls.clear();
        int s_cnt = 0;
        for (int i = 0; i < 25; i++) {
            if (arr[i] != 0)
                continue;
            int r = idx[i].first;
            int c = idx[i].second;
            girls.insert({{r, c}, map[r][c]});
        }
        for (auto cur: girls) {
            if (cur.second == 'S')
                s_cnt++;
        }
        if (s_cnt >= 4 && is_all_near())
            ans++;


    } while (next_permutation(arr.begin(), arr.end()));
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
    cout << ans;
}