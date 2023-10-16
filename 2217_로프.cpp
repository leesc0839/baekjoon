//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int rope;
        cin >> rope;
        v.emplace_back(rope);
    }
    std::sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        v.emplace_back(v[0] * (N - i));
        v.erase(v.begin());
    }

    std::sort(v.begin(), v.end(),greater<int>());
    cout<<*v.begin();
}
