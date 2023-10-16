#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[10001], dist[10002];
int N, a, b;
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cin >> a >> b;
    fill(dist, dist + sizeof(dist) / sizeof(int), -1);

    Q.push(a);
    dist[a] = 0;
    while (!Q.empty()) {
        auto c = Q.front();
        Q.pop();
        for (int i = c; i <= N; i += arr[c]) {
            if(dist[i] == -1){
                dist[i] = dist[c] + 1;
                Q.push(i);
            }
            if(i == b){
                cout<< dist[i];
                return 0;
            }
        }

        for (int i = c; i > 0; i -= arr[c]) {
            if(dist[i] == -1){
                dist[i] = dist[c] + 1;
                Q.push(i);
            }

            if(i == b){
                cout<< dist[i];
                return 0;
            }
        }
    }
    cout << -1;
}