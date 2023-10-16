//
// Created by 이승철 on 2022/08/27.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
 * n(vertex , 건물의 개수 : 1 ~ 1000)
 * k(edge , 건물 건설 간 규칙 : 1 ~ 100000)
 */
int t, n, k, u, v, finish_vertex;
int in_degree[1005];
int vertex_weight[1005];
int ans[1005];
vector<vector<int>> edge;

void clear() {
    for (int i = 0; i < 1005; i++)
        in_degree[i] = vertex_weight[i] = ans[i] = 0;
    edge.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        clear();
        edge.resize(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> vertex_weight[i];

        for (int i = 0; i < k; i++) {
            cin >> u >> v;
            edge[u].push_back(v);
            in_degree[v]++;
        }

        cin >> finish_vertex;
        /*
         * priority_queue 를 쓴 이유
         * finish_vertex의 indegree가 0이 되는 순간은 선행 조건 중 누적 weight가 가장 큰 것이어야 함.
         * 예를 들면 7이 finish_vertex이고 7의 선행조건이 5,6이며 버텍스 5와 6의 누적 weight가 10 20이라면
         * 5가 7을 접근할 때 7의 indegree를 -1, 6이 7을 접근할 때 7의 indegree를 0으로 만들고
         * 6의 누적 weight 20이 7에 영향을 끼침
         * 따라서 pq를 통해 5가 7에 먼저 접근하고, 6이 7을 막타 치게 할 수 있음
         */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;

        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0)
                PQ.push({vertex_weight[i], i});
        }

        while (!PQ.empty()) {
            auto cur = PQ.top();
            PQ.pop();
            if(cur.second == finish_vertex){
                cout << cur.first;
                break;
            }

            ans[cur.second] = cur.first;

            for (auto c: edge[cur.second]) {
                in_degree[c]--;
                if (in_degree[c] == 0)
                    PQ.push({vertex_weight[c] + cur.first, c});
            }
        }
        cout << ans[finish_vertex] << '\n';
    }
}
