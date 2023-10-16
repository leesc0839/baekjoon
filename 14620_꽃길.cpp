//
// Created by 이승철 on 2022/08/09.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, rtn_min = 16 * 201;
int board[11][11];
bool visit[11][11];
int dr[5] = {-1, 0, 1, 0, 0};
int dc[5] = {0, 1, 0, -1, 0};
vector<pair<int, int>> v;
int isUsed[100];
pair<int, int> arr[3];

void clearVisit() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
    }
}

void choosePlace(int cur, int idx) {
    if (cur == 3) {
        int s = 0;
        for (int i = 0; i < 3; i++) {
            auto c = arr[i];
            for (int j = 0; j < 5; j++) {
                int nr = c.first + dr[j];
                int nc = c.second + dc[j];
                if (visit[nr][nc]) {
                    clearVisit();
                    return;
                } else {
                    visit[nr][nc] = true;
                    s += board[nr][nc];
                }
            }
        }
        rtn_min = min(rtn_min, s);
        clearVisit();
        return;
    }
    for (int i = idx; i < v.size(); i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            arr[cur] = v[i];
            choosePlace(cur + 1, i+1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++)
            cin >> board[r][c];
    }

    for (int r = 2; r < N; r++) {
        for (int c = 2; c < N; c++)
            v.emplace_back(r, c);
    }
    choosePlace(0, 0);
    cout << rtn_min;
}
