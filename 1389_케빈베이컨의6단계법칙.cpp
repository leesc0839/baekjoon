//
// Created by 이승철 on 2022/08/21.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int v, e, srt, dst, rtn;
int min_sum = 500005;
vector<int> edge[105];
int visit[105];

void bfs(int start) {
    /*
     * 거리를 구하는 문제 이기 때문에 바로 bfs 라는 것을 알 수 있다.
     * visit 배열에는 start, destination 의 거리를 저장함과 동시에, 방문 여부를 결정한다.
     * 자기 자신은 원래 거리가 0이지만, 방문을 표시하기 위해, 0이 아닌 1로 설정했고,
     * 값을 구할 때 -1로 처리 하였다.
     */
    queue<int> Q;
    Q.push(start);
    visit[start] = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto dest: edge[cur]) {
            if (!visit[dest]) {
                visit[dest] = visit[cur] + 1;
                Q.push(dest);
            }
        }
    }
}

bool clear() {
    /*
     * visit 배열 clear 동시에, count 갯수를 합하고, 현재 까지 최소 인지 아닌지 bool 형태로 return 한다.
     */
    int sum = 0;
    for (int i = 1; i <= v; i++) {
        sum += visit[i] - 1;
        visit[i] = 0;
    }

    if (min_sum > sum) {
        min_sum = sum;
        return true;
    } else
        return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> srt >> dst;
        edge[srt].push_back(dst);
        edge[dst].push_back(srt);
    }

    for (int start = 1; start <= v; start++) {
        bfs(start);
        if (clear())
            rtn = start;
    }
    cout << rtn;
}