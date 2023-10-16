//
// Created by 이승철 on 2022/09/27.
//
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
char map[13][7];
bool visit[13][7];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs(int r, int c, char C) {
    queue<pair<int, int>> Q;
    stack<pair<int, int>> erase_stack;
    Q.push({r, c});
    erase_stack.push({r, c});
    visit[r][c] = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6 || visit[nr][nc])
                continue;
            if (map[nr][nc] == C) {
                visit[nr][nc] = true;
                Q.push({nr, nc});
                erase_stack.push({nr, nc});
            }
        }
    }

    if (erase_stack.size() >= 4) {
        while (!erase_stack.empty()) {
            auto cur = erase_stack.top();
            erase_stack.pop();
            map[cur.first][cur.second] = 'X';
        }
    }
}

void init() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++)
            visit[i][j] = false;
    }
}

void flood_fill(char C) {
    for (int r = 0; r < 12; r++) {
        for (int c = 0; c < 6; c++) {
            if (map[r][c] == '.' || visit[r][c] || map[r][c] != C)
                continue;
            bfs(r, c, C);
        }
    }
}

bool eraseX() {
    bool isX = false;
    for (int c = 0; c < 6; c++) {
        stack<char> S;
        for (int r = 0; r < 12; r++) {
            if (map[r][c] != '.' && map[r][c] != 'X')
                S.push(map[r][c]);
            if (map[r][c] == 'X')
                isX = true;
            map[r][c] = '.';
        }
        int idx = 11;
        while (!S.empty()) {
            map[idx][c] = S.top();
            S.pop();
            idx--;
        }
    }
    return isX;
}

void find_pop() {
    int cnt = 0;
    while (true) {
        flood_fill('R');
        flood_fill('G');
        flood_fill('B');
        flood_fill('P');
        flood_fill('Y');
        if (!eraseX()) {
            cout << cnt;
            return;
        }
        init();
        cnt++;
    }
}

void input() {
    for (int r = 0; r < 12; r++) {
        for (int c = 0; c < 6; c++) {
            cin >> map[r][c];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    find_pop();
}
