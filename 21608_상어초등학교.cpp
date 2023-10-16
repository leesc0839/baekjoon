//
// Created by 이승철 on 2022/09/26.
//
#include <iostream>
#include <queue>
#include <unordered_set>

#define MAX 10000
using namespace std;
int map[MAX][MAX], N, student_idx, elem, ans;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
unordered_set<int> student_like[MAX];

void find_seat(int student) {
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, less<>> pq;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int liked_cnt = 0;
            int blank_cnt = 0;

            if (map[r][c] > 0)
                continue;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 1 || nr > N || nc < 1 || nc > N)
                    continue;
                if (map[nr][nc] == 0)
                    blank_cnt++;
                else if (map[nr][nc] > 0) {
                    if (student_like[student].count(map[nr][nc]))
                        liked_cnt++;
                }
            }
            if (!pq.empty()) {
                if (pq.top().first.first == liked_cnt && pq.top().first.second == blank_cnt) {
                    if (pq.top().second.first > r) {
                        pq.pop();
                        pq.push({{liked_cnt, blank_cnt},
                                 {r,         c}});
                    } else if (pq.top().second.first == r) {
                        if (pq.top().second.second > c) {
                            pq.pop();
                            pq.push({{liked_cnt, blank_cnt},
                                     {r,         c}});
                        }
                    }
                } else
                    pq.push({{liked_cnt, blank_cnt},
                             {r,         c}});
            } else
                pq.push({{liked_cnt, blank_cnt},
                         {r,         c}});
        }
    }
    map[pq.top().second.first][pq.top().second.second] = student;
}

void sol() {
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        cin >> student_idx;
        for (int j = 0; j < 4; j++) {
            cin >> elem;
            student_like[student_idx].insert(elem);
        }
        find_seat(student_idx);
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int liked = 0;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 1 || nr > N || nc < 1 || nc > N)
                    continue;
                if (student_like[map[r][c]].count(map[nr][nc]))
                    liked++;
            }
            if (liked == 1)
                ans += 1;
            else if (liked == 2)
                ans += 10;
            else if (liked == 3)
                ans += 100;
            else if (liked == 4)
                ans += 1000;
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}
