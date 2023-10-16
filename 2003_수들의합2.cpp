//
// Created by 이승철 on 2023/10/04.
//
#include <iostream>

using namespace std;
const int MX = 10005;
int N, M, arr[MX];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
}

int sol() {
    int answer = 0;
    int tot = 0;
    int ed = 1;

    for (int st = 1; st <= N; st++) {
        while (ed <= N && tot < M) {
            tot += arr[ed];
            ed++;
        }
        if (tot == M)
            answer++;

        tot -= arr[st];
    }
    return answer;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << sol();
}