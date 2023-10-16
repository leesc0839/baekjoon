//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define K 6
using namespace std;
int N, elem;
vector<int> combination;
vector<int> zeroOneV;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        combination.clear();
        zeroOneV.clear();

        cin >> N;
        if (!N)
            break;
        for (int i = 0; i < K; i++)
            zeroOneV.push_back(1);

        for (int i = 0; i < N - K; i++)
            zeroOneV.push_back(0);

        for (int i = 0; i < N; i++) {
            cin >> elem;
            combination.push_back(elem);
        }

        do {
            for (int i = 0; i < N; i++) {
                if (zeroOneV[i] == 1)
                    cout << combination[i] << " ";
            }
            cout << '\n';
        } while (prev_permutation(zeroOneV.begin(), zeroOneV.end()));
        cout<<'\n';
    }
}

