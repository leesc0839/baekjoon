//
// Created by 이승철 on 2022/07/24.
//
#include <iostream>
#include <vector>

using namespace std;
int arrSize;
int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> arrSize;
    vector<int> v;
    v.reserve(arrSize);
    for (int i = 0; i < arrSize; i++) {
        int k;
        cin >> k;
        v.push_back(k);
        arr[i] = k;
    }

    auto iter = v.begin();

    for (int i = 0; i < arrSize; i++) {
        cout << arr[upper_bound(++iter, v.end(), arr[i]) - iter];
    }

}

