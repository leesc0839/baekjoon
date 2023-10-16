//
// Created by 이승철 on 2023/09/17.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n;

void sol() {
    int cnt = 0;
    for (int i = 0; i < 10; i++)
        v.emplace_back(i);
    do {
        int a = v[0] * 10000 + v[1] * 1000 + v[2] * 100 + v[3] * 10 + v[4];
        int b = v[5] * 10000 + v[6] * 1000 + v[7] * 100 + v[8] * 10 + v[9];

        if (a == b * 9) {
            cnt++;
            if (cnt == n) {
                for (int i = 0; i < 5; i++)
                    cout << v[i];
                cout << ' ';
                for (int i = 5; i < 10; i++)
                    cout << v[i];
                return;
            }
        }

    } while (next_permutation(v.begin(), v.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sol();
}
