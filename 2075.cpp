#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[2260000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N * N; i++)
        cin >> arr[i];
    sort(arr, arr + N * N, greater<int>());
    cout << arr[N - 1];
}