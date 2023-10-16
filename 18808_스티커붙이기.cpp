//
// Created by 이승철 on 2022/09/23.
//
#include <iostream>
#include <vector>

#define MAX 41
using namespace std;
int R, C, K, sticker_r, sticker_c, elem, ans;
int map[MAX][MAX];
vector<pair<int, int>> sticker[101];
pair<int, int> sticker_size[101];

void input() {
    cin >> R >> C >> K;
    for (int i = 0; i < K; i++) {
        cin >> sticker_r >> sticker_c;
        sticker_size[i] = {sticker_r, sticker_c};
        for (int r = 0; r < sticker_r; r++) {
            for (int c = 0; c < sticker_c; c++) {
                cin >> elem;
                if (elem == 1)
                    sticker[i].emplace_back(r, c);
            }
        }
    }
}

void put_sticker(int start_r, int start_c, int sticker_idx) {
    for (auto cur: sticker[sticker_idx])
        map[start_r + cur.first][start_c + cur.second] = 1;
}

bool is_possible_put_sticker(int sticker_idx) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            bool isPossible = true;

            for (auto cur: sticker[sticker_idx]) {
                int nxt_r = cur.first + i;
                int nxt_c = cur.second + j;
                if (nxt_r < 0 || nxt_r >= R || nxt_c < 0 || nxt_c >= C || map[nxt_r][nxt_c] == 1) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) {
                put_sticker(i, j, sticker_idx);
                return true;
            }
        }
    }
    return false;
}

void rotate_sticker(int sticker_idx) {
    vector<pair<int, int>> tmp;
    for (auto cur: sticker[sticker_idx])
        tmp.emplace_back(cur.second, (sticker_size[sticker_idx].first - 1) - cur.first);
    sticker_size[sticker_idx] = {sticker_size[sticker_idx].second, sticker_size[sticker_idx].first};
    sticker[sticker_idx] = tmp;
}

void sol() {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 4; j++) {
            if (is_possible_put_sticker(i))
                break;
            rotate_sticker(i);
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            if (map[i][j] == 1)
                ans++;
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}