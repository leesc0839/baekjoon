//
// Created by 이승철 on 2022/11/07.
//
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define MAX 105
using namespace std;
int T, R, C;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char board[MAX][MAX], board_input[MAX][MAX];
bool visit[MAX][MAX];
string key_string;
set<int> key;
set<pair<int, int>> ans;
queue<pair<int, int>> Q;
map<pair<int, int>, int> tmp;
vector<pair<int, int>> v;

void init() {
    for (int i = 0; i <= R + 1; i++)
        fill(visit[i], visit[i] + C + 2, false);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            board[i + 1][j + 1] = board_input[i][j];
    }

    for (int i = 0; i <= R + 1; i++) {
        for (int j = 0; j <= C + 1; j++) {
            if (i == 0 || i == R + 1 || j == 0 || j == C + 1)
                board[i][j] = '.';
        }
    }
    Q.push({0, 0});
    visit[0][0] = true;
    key_string = "";
    key.clear();
    ans.clear();
    tmp.clear();
}

bool push_new_key() {
    bool is_new = false;
    v.clear();
    for (auto cur: tmp) {
        int need_key = cur.second;
        int r = cur.first.first;
        int c = cur.first.second;

        if (!key.count(need_key))
            continue;

        is_new = true;
        visit[r][c] = true;
        Q.push({r, c});
        v.emplace_back(r, c);
    }
    for (auto cur: v)
        tmp.erase({cur.first, cur.second});
    return is_new;
}

bool OOB(int r, int c) {
    if (r < 0 || r > R + 1 || c < 0 || c > C + 1 || visit[r][c] || board[r][c] == '*')
        return true;
    return false;
}

bool can_open_door(int r, int c) {
    if (key.count(board[r][c] + 32))
        return true;

    tmp.insert({{r, c}, (int) board[r][c] + 32});
    return false;
}

void bfs() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (OOB(nr, nc))
                continue;
            if ((0 <= board[nr][nc] - 'A') && (board[nr][nc] - 'A' < 26)) //door
                if (!can_open_door(nr, nc)) // can't open, memorize
                    continue;

            if ((0 <= board[nr][nc] - 'a') && (board[nr][nc] - 'a' < 26)) //key
                key.insert((int) board[nr][nc]);

            if (board[nr][nc] == '$')
                ans.insert({nr, nc});

            visit[nr][nc] = true;
            Q.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                cin >> board_input[i][j];
        }
        init();
        cin >> key_string;
        for (auto cur: key_string) {
            if (cur == '0')
                break;
            key.insert((int) cur);
        }
        while (true) {
            bfs();
            if (!push_new_key())
                break;

        }
        cout << ans.size() << '\n';
    }
}
