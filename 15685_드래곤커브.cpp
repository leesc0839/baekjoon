//
// Created by 이승철 on 2022/12/24.
//
#include <iostream>
#include <queue>

using namespace std;
const int MX = 30000;
bool visit[MX][MX];
int N, x, y, d, g;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int checkx[4] = {0, 1, 0, 1};
int checky[4] = {0, 0, 1, 1};

bool OBB(int x, int y) {
    if (x < 0 || x > 100 || y < 0 || y > 100)
        return true;
    return false;
}

void dragon(int x, int y, int d, int g) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<>> pq;
    //level 0
    pq.push({0, {x, y}});
    pq.push({1, {x + dx[d], y + dy[d]}});
    visit[x][y] = true;
    visit[x + dx[d]][y + dy[d]] = true;
    if (g == 0)
        return;
    // level 1 ~

    for (int i = 1; i <= g; i++) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<>> pq2 = pq;
        int standardX = pq2.top().second.first;
        int standardY = pq2.top().second.second;
        pq2.pop();

        while (!pq2.empty()) {
            auto cur = pq2.top();
            pq2.pop();
            int nx, ny;
            nx = standardX - abs(standardY - cur.second.second);
            ny = standardY + abs(standardX - cur.second.first);


            int dist = abs(x - nx) + abs(y - ny);

            if (!OBB(nx, ny))
                visit[nx][ny] = true;

            pq.push({dist, {nx, ny}});

        }
    }
}

void sol() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        dragon(x, y, d, g);
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            bool isPos = true;
            for (int k = 0; k < 4; k++) {
                if (!visit[i + checkx[k]][j + checky[k]])
                    isPos = false;
            }
            if (isPos)
                ans++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}
