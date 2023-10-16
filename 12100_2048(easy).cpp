//
// Created by 이승철 on 2022/09/25.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 21

using namespace std;
int map[MAX][MAX], map_copied[MAX][MAX], N, ans;
vector<int> arr;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }
}

void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            map_copied[i][j] = map[i][j];
    }
}

void move_left() {
    for (int r = 0; r < N; r++) {
        stack<pair<int, bool>> S;
        for (int c = 0; c < N; c++) {
            if (map_copied[r][c] == 0)
                continue;
            if (S.empty())
                S.push({map_copied[r][c], false});
            else {
                if ((S.top().first == map_copied[r][c]) && !S.top().second) {
                    S.pop();
                    S.push({2 * map_copied[r][c], true});
                } else
                    S.push({map_copied[r][c], false});
            }
            map_copied[r][c] = 0;
        }

        while (!S.empty()) {
            map_copied[r][S.size() - 1] = S.top().first;
            S.pop();
        }
    }
}

void move_right() {
    for (int r = 0; r < N; r++) {
        stack<pair<int, bool>> S;
        for (int c = N - 1; c >= 0; c--) {
            if (map_copied[r][c] == 0)
                continue;
            if (S.empty())
                S.push({map_copied[r][c], false});
            else {
                if ((S.top().first == map_copied[r][c]) && !S.top().second) {
                    S.pop();
                    S.push({2 * map_copied[r][c], true});
                } else
                    S.push({map_copied[r][c], false});
            }
            map_copied[r][c] = 0;
        }

        while (!S.empty()) {
            map_copied[r][N - S.size()] = S.top().first;
            S.pop();
        }
    }
}

void move_north() {
    for (int c = 0; c < N; c++) {
        stack<pair<int, bool>> S;
        for (int r = 0; r < N; r++) {
            if (map_copied[r][c] == 0)
                continue;
            if (S.empty())
                S.push({map_copied[r][c], false});
            else {
                if (S.top().first == map_copied[r][c] && !S.top().second) {
                    S.pop();
                    S.push({2 * map_copied[r][c], true});
                } else
                    S.push({map_copied[r][c], false});
            }
            map_copied[r][c] = 0;
        }
        while (!S.empty()) {
            map_copied[S.size() - 1][c] = S.top().first;
            S.pop();
        }
    }
}

void move_south() {
    for (int c = 0; c < N; c++) {
        stack<pair<int, bool>> S;
        for (int r = N - 1; r >= 0; r--) {
            if (map_copied[r][c] == 0)
                continue;
            if (S.empty())
                S.push({map_copied[r][c], false});
            else {
                if (S.top().first == map_copied[r][c] && !S.top().second) {
                    S.pop();
                    S.push({2 * map_copied[r][c], true});
                } else
                    S.push({map_copied[r][c], false});
            }
            map_copied[r][c] = 0;
        }

        while (!S.empty()) {
            map_copied[N - S.size()][c] = S.top().first;
            S.pop();
        }
    }
}

void move(int dir) {
    if (dir == 0)
        move_north();
    else if (dir == 1)
        move_south();
    else if (dir == 2)
        move_left();
    else if (dir == 3)
        move_right();
}

void sol() {
    const int max_num = 1024;
    for (int i = 0; i < max_num; i++) {
        int cur_num = i;
        arr.clear();
        for (int j = 0; j < 5; j++) {
            arr.push_back(cur_num % 4);
            cur_num /= 4;
        }
        // vector 에 움직일 방향이 정해진 상태
        for (auto cur: arr)
            move(cur);

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++)
                ans = max(ans, map_copied[r][c]);
        }
        copy_map();
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
