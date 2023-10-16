//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, d, max_cnt, max_height; // n(크기) : 2~100 , d(높이) : 1~100
bool visit[101][101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, int height) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;
        if (visit[nr][nc][height])
            continue;

        visit[nr][nc][height] = true;
        dfs(nr, nc, height);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    /*
     * connected component 개수 출력 문제
     * 입력 받을 때, 높이에 따라 잠길 곳은 미리 방문 처리를 한다.
     * 그리고 0부터 최대 높이까지 방문하지 않은 곳을 dfs를 돌려 방문하게 만든다.
     * dfs를 탈출하면, 현재 높이의 counting 변수에 +1하고, 마지막에 출력할 전역변수와 값을 비교해 크면 저장한다.
     */
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> d;
            max_height = max(max_height, d);
            /*
             * 높이에 따라 잠기는 구역 표시 (최대 높이 100 부터 입력 값까지 방문 처리)
             */
            for (int height = 100; height >= d; height--)
                visit[r][c][height] = true;
        }
    }

    for (int height = 0; height < max_height; height++) {
        int cnt = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (!visit[r][c][height]) {
                    cnt++;
                    visit[r][c][height] = true;
                    dfs(r, c, height);
                }
            }
        }
        max_cnt = max(max_cnt, cnt);
    }
    cout << max_cnt;
}

