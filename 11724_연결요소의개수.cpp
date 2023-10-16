//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <vector>

using namespace std;
int n, m, cnt;
vector<int> edge[1005];
bool visit[1005];

void dfs(int v) {
    for (auto c: edge[v]) {
        if (!visit[c]) {
            visit[c] = true;
            dfs(c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    /*
     * 2차원 배열 보단, 2차원 vector 에 데이터 를 담아, 존재 하는 간선만 탐색 하도록 한다.
     */
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }
    /*
     * for문을 통해 모든 버텍스들을 dfs 돌린다.
     * 방문하지 않는 버텍스를 관찰하고, dfs를 통해 연결요소들을 방문처리 한다.
     * 이렇게 되면, 자동적으로 방문된 버텍스들은 지나치게 된다.
     */

    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            visit[i] = true;
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}

