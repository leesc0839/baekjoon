//
// Created by 이승철 on 2023/10/05.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MX = 100005;
int N, arr[MX], X;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> X;
}

int sol() {
    int answer = 0;
    sort(arr, arr + N);

    int st = 0;
    int ed = N - 1;

    while (st != ed) {
        int tot = arr[st] + arr[ed];
        if (tot == X) {
            answer++;
            st++;
        } else if (tot < X)
            st++;
        else if (tot > X)
            ed--;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << sol();
}


