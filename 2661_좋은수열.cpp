//
// Created by 이승철 on 2022/08/09.
//
#include <iostream>

using namespace std;
int n;
int arr[81];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            arr[i] = 1;
        else if (i % 4 == 1)
            arr[i] = 2;
        else if (i % 4 == 3)
            arr[i] = 3;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i];

}