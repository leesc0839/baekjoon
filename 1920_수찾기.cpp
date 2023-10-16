//
// Created by 이승철 on 2023/09/21.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 100005;
int N, M, arr[MX], A;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

bool check(int a) {
    return binary_search(arr, arr+N, a);
}

void sol() {
    sort(arr, arr + N);
    cin >> M;
    while (M--) {
        cin >> A;
        check(A) ? cout << "1\n" : cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();
}