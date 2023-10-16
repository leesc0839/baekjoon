//
// Created by 이승철 on 2022/08/14.
//
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fill(arr, arr + 1000001, 1000001);
    arr[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (i % 3 == 0)
            arr[i] = min(arr[i], arr[i / 3] + 1);
        if (i % 2 == 0)
            arr[i] = min(arr[i], arr[i / 2] + 1);
        arr[i] = min(arr[i], arr[i - 1] + 1);

    }
    cout << arr[N];
}
