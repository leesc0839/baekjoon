//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <vector>

using namespace std;
int v, e, srt, dst, cnt = 1, mx;
vector<int> edge[10005];
int arr[10005];
bool visit[10005];

void dfs(int start) {
    for (auto c: edge[start]) {
        if (!visit[c]) {
            visit[c] = true;
            cnt++;
            dfs(c);
        }
    }
}

/*
 * visit 배열과, counting 변수를 초기화 한다.
 */
void clear(int s) {
    for (int i = 1; i <= v; i++)
        visit[i] = false;
    mx = max(mx, cnt);
    arr[s] = cnt;
    cnt = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    /*
     * 방향이 있는 edge 이기 때문에, start, destination 을 확실히 설정한다.
     */
    for (int i = 0; i < e; i++) {
        cin >> dst >> srt;
        edge[srt].push_back(dst);
    }
    /*
     * dfs를 시작하기 전, visit 처리를 해주고, visit 배열을 clear한다.
     */

    for (int start = 1; start <= v; start++) {
        visit[start] = true;
        dfs(start);
        clear(start);
    }
    for (int i = 1; i <= v; i++) {
        if (mx == arr[i])
            cout << i << ' ';
    }

}

