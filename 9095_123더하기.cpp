//
// Created by 이승철 on 2022/08/14.
//
#include <iostream>

using namespace std;
int arr[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4; i<=11; i++)
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
    int t;
    cin >> t;
    while (t--) {
        int e;
        cin >> e;
        cout << arr[e] << '\n';
    }
}
