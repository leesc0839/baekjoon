//
// Created by 이승철 on 2022/08/01.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N, MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    std::sort(v.begin(), v.end());
    MAX = *v.begin(); // 가능한 나머지

    vector<int> return_v;
    for (int i = 0; i <= MAX; i++) {
        int target = v[N - 1] - i;
        if (target == 1)
            continue;

        int m = v[0] % target;
        for (int j = 0; j < N; j++) {
            if (v[j] % target != m)
                break;

            if (j == N - 1)
                return_v.emplace_back(target);
        }
        // ( 가장 큰 수 - 가능한 나머지 ) 소인수 분해 후 나누고, 만약 그 수가 답 이라면 vector 에 push
        for (int j = 2; j*j <= target; j++) {

            while (target % j == 0) {
                target /= j;
                if (target == 1)
                    break;

                int m = v[0] % target;
                for (int k = 0; k < N; k++) {
                    if (v[k] % target != m)
                        break;

                    if (k == N - 1)
                        return_v.emplace_back(target);
                }
            }
        }

    }
    std::sort(return_v.begin(), return_v.end());

    for (auto e: return_v)
        cout << e << ' ';


}

