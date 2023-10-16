//
// Created by 이승철 on 2022/08/14.
//
#include <iostream>

using namespace std;
int n, m;
int arr[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        arr[i] = e + arr[i - 1];
    }
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << arr[e] - arr[s - 1]<<'\n';
    }
}
