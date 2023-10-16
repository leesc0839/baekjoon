#include <iostream>
#include <vector>

using namespace std;

int visited[101];
int inputMatrix[101][101];
int outputMatrix[101][101];
int currentIndex;
int cnt;

void dfs(int index, int N) {
    if (cnt != 0) {
        outputMatrix[currentIndex][index] = 1;
    }
    cnt++;
    visited[index] = true;
    for (int i = 0; i < N; i++) {
        if (inputMatrix[index][i] == 1 && visited[i] && i==currentIndex) {
            dfs(i, N);
        }
        if (inputMatrix[index][i] == 1 && !visited[i])
            dfs(i, N);

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> inputMatrix[i][j];
    }

    for (int i = 0; i < N; i++) {
        currentIndex = i;

        for (int j = 0; j < N; j++)
            visited[j] = false;

        cnt = 0;
        dfs(i, N);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << outputMatrix[i][j] << " ";
        cout << '\n';
    }


}
