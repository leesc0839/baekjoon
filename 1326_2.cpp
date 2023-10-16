#include <iostream>

using namespace std;

int arr[10001];
bool visit[10001];
int N, a, b;
int cnt;
int min = 10001;
bool isPossible;

void dfs(int cur){
    cnt++;
    visit[cur] = true;
    if(!visit[cur])
    dfs(arr[cur]);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> a >> b;
    dfs(a);
    if ((b - a) % arr[a] == 0) {
        isPossible = true;
        cout<<cnt;
        return 0;
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if ((b - a) % cur.data == 0) {
            isPossible = true;
            break;
        }

        int i = 1;
        int moveIdx;
        while (true) {
            moveIdx = cur.idx - i * (cur.data);
            if (moveIdx < 1) break;
            Q.push({moveIdx, arr[moveIdx]});
            i++;
        }
        int j = 1;
        while (true) {
            moveIdx = cur.idx + j * cur.data;
            if (moveIdx > N) break;
            Q.push({moveIdx, arr[moveIdx]});
            j++;
        }
        cnt++;
    }
    if (!isPossible)
        cout << -1;
    else
        cout << cnt;
}