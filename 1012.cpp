//
// Created by 이승철 on 2022/07/02.
//
#include <iostream>

using namespace std;
int M, N, K;
int x, y;
int matrix[51][51];
bool visited[51][51];
int cnt;
bool k = false;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
void dfs(int a, int b) {
    if (matrix[a][b]==0 || visited[a][b])
        return;
    k = true;
    visited[a][b] = true;
    for (int i = 0; i < 4; ++i) {
        int next_a = a + dr[i];
        int next_b = b + dc[i];

    }

}
void printV(){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            matrix[y][x] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(matrix[i][j]){
                    cout<<"##\n";
                    printV();
                    cout<<"##\n";
                }
                dfs(i, j);
                if (k)
                    cnt++;
                k = false;
            }
        }

        cout << cnt << '\n';

        for (int i = 0; i < N; i++) { // 초기화
            for (int j = 0; j < M; j++) {
                matrix[i][j] = 0;
                visited[i][j] = false;
            }
        }

        cnt = 0;


    }
}



