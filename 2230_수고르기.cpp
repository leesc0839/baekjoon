//
// Created by 이승철 on 2023/08/30.
//
#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 100005;
int N, M, arr[MX];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

int sol() {
    int answer = 0x7fffffff;

    int en = 0;
    sort(arr, arr + N);
    for (int st = 0; st < N; st++) {
        while(en < N){
            int diff = arr[en] - arr[st];
            if (diff >= M) {
                answer = min(answer, diff);
                break;
            }
            en++;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << sol();

}



