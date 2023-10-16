//
// Created by 이승철 on 2022/08/26.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, from, to;
vector<vector<int>> edge;
int in_degree[32005];
queue<int> Q;

/*
 * n(vertex 개수) 1 ~ 32000
 * m(directed edge 개수) 1 ~ 100000
 * vertex 간 선후 관계가 존재하고,
 * 순서를 정해야 하는 상황이니 위상정렬 문제이다.
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    edge.resize(n + 1);
    for (int i = 0; i < m; i++) { // in_degree , edge 정보들 저장
        cin >> from >> to;
        edge[from].push_back(to);
        in_degree[to]++;
    }

    for (int i = 1; i <= n; i++) // 초기 그래프에서 in_degree가 0인 vertex Q에 Push
        if (in_degree[i] == 0)
            Q.push(i);

    while (!Q.empty()) { // 인접한 버텍스의 in_degree를 -1 해주는 작업 -> edge가 없어진다고 생각하면 됨
        auto cur = Q.front();
        Q.pop();
        cout << cur << ' '; // visit
        for (auto adjacent: edge[cur]) {
            in_degree[adjacent]--;
            if (in_degree[adjacent] == 0)
                Q.push(adjacent);
        }
    }


}
