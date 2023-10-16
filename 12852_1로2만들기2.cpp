//
// Created by 이승철 on 2022/08/14.
//
#include <iostream>
#include <algorithm>

using namespace std;
int x;
int arr[1000005];
int dir_arr[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    arr[1] = 0;
    for (int i = 2; i <= x; i++) {
        arr[i] = arr[i - 1] + 1;
        dir_arr[i] = i - 1;
        if (i % 2 == 0 && arr[i] > arr[i / 2] + 1) {
            arr[i] = arr[i / 2] + 1;
            dir_arr[i] = i / 2;
        }
        if (i % 3 == 0 && arr[i] > arr[i / 3] + 1) {
            arr[i] = arr[i / 3] + 1;
            dir_arr[i] = i / 3;
        }
    }

    cout << arr[x] << '\n';
    int cur = x;
    while (true) {
        cout << cur << ' ';
        if (cur == 1)
            break;
        cur = dir_arr[cur];
    }
}

