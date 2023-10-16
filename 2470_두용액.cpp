//
// Created by 이승철 on 2023/10/05.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int MX = 100005;
int N, arr[MX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void sol() {
    pair<int, int> answer;

    sort(arr, arr + N);
    int cur = INT32_MAX;
    int st = 0;
    int ed = N - 1;

    while (st != ed) {
        int num = abs(arr[st] + arr[ed]);
        if (cur > num) {
            cur = num;
            answer = {arr[st], arr[ed]};
        }

        int a = abs(arr[st + 1] + arr[ed]);
        int b = abs(arr[st] + arr[ed - 1]);

        a <= b ? st++ : ed--;
    }
    cout << answer.first << ' ' << answer.second << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();
}