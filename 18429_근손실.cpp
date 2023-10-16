//
// Created by 이승철 on 2022/08/05.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, bool>> v;
int arr[8];
int rtn_val;

void shuffle(int c) {
    if (N == c) {
        int cur = 0;
        bool isPossible = true;
        for (int i = 0; i < N; i++) {
            cur += (arr[i] - K);
            if (cur < 0) {
                isPossible = false;
                break;
            }
        }
        if (isPossible)
            rtn_val++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!v[i].second) {
            v[i].second = true;
            arr[c] = v[i].first;

            shuffle(c + 1);

            v[i].second = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = false;
    }

    std::sort(v.begin(), v.end());
    shuffle(0);
    cout<<rtn_val;
}

