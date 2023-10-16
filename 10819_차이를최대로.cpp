//
// Created by 이승철 on 2022/08/04.
//
#include <iostream>
#include <vector>

using namespace std;
int N, return_value, tmp;
int arr[8];
bool isUsed[8];
vector<int> v;

void back_tracking(int cnt) {
    if (cnt == N) {
        for (int i = 0; i < N - 1; i++)
            tmp += arr[i] - arr[i + 1] > 0 ? arr[i] - arr[i + 1] : -(arr[i] - arr[i + 1]);

        return_value = max(return_value, tmp);
        tmp = 0;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!isUsed[i]) {
            arr[cnt] = v[i];
            isUsed[i] = true;
            back_tracking(cnt + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    back_tracking(0);
    cout << return_value;
}
