//
// Created by 이승철 on 2022/08/01.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> v;
vector<int> zeroOneV;
char elem;
int length, ele_cnt;
int V, C;

void makePassword() {
    std::sort(v.begin(), v.end());
    std::sort(zeroOneV.begin(), zeroOneV.end(),greater<int>());
    do {
        for (int i = 0; i < ele_cnt; i++) {
            if (zeroOneV[i] == 1 && (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u'))
                V++;
            else if (zeroOneV[i] == 1)
                C++;
        }
        if (V >= 1 && C >= 2) {
            for (int i = 0; i < ele_cnt; i++) {
                if (zeroOneV[i] == 1)
                    cout << v[i];
            }
            cout << '\n';
        }
        V = C = 0;
    } while (prev_permutation(zeroOneV.begin(), zeroOneV.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> length >> ele_cnt;
    for (int i = 0; i < ele_cnt; i++) {
        cin >> elem;
        v.emplace_back(elem);
    }
    for (int i = 0; i < length; i++)
        zeroOneV.emplace_back(1);

    for (int i = 0; i < ele_cnt - length; i++)
        zeroOneV.emplace_back(0);

    makePassword();
}


