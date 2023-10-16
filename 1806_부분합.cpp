//
// Created by 이승철 on 2023/08/30.
//
#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 100005;
const int INF = 0x7fffffff;
int N, S, arr[MX];

void input() {
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

int sol() {
    int answer = INF;
    int en = -1;
    int sum = 0;

    for (int st = 0; st < N; st++) {
        while (en < N) {
            if (sum >= S) {
                answer = min(answer, en - st + 1);
                break;
            }
            en++;
            sum += arr[en];
        }
        sum -= arr[st];
    }

    return answer == INF ? 0 : answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << sol();
}
