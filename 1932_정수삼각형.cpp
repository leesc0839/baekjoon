//
// Created by 이승철 on 2022/08/15.
//
#include <iostream>
#include <algorithm>

using namespace std;
int n, rtn_max; //1~500
int tri[505][505], dist[505][505]; // elem 0~9999
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
        }
    }
    dist[1][1] = tri[1][1];
    dist[2][1] = dist[1][1] + tri[2][1];
    dist[2][2] = dist[1][1] + tri[2][2];

    for (int r = 3; r <= n; r++) {
        for (int c = 1; c <= r; c++) {
            dist[r][c] = max(dist[r - 1][c - 1], dist[r - 1][c]) + tri[r][c];
        }
    }

    for (int c = 1; c <= n; c++)
        rtn_max = max(rtn_max, dist[n][c]);

    cout << rtn_max<<'\n';


}
