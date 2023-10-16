//
// Created by 이승철 on 2022/08/15.
//
#include <iostream>
#include <algorithm>

using namespace std;
int n, rtn_value;
int arr[1005], length[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    fill(length, length + 1005, 1);
    for (int cur = 0; cur < n; cur++) {
        for (int prev = 0; prev < cur; prev++) {
            if (arr[cur] > arr[prev]) // 현재 값 보다 앞이고 작은 수들 중, 가장 부분 수열의 길이가 큰 값 +1
                length[cur] = max(length[cur], length[prev] + 1);
        }
    }

    for (int i = 0; i < n; i++)
        rtn_value = max(rtn_value, length[i]);
    cout << rtn_value;

}