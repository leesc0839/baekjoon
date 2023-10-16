//
// Created by 이승철 on 2022/08/09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isUsed[26];
vector<string> s_v;
int n, k, max_cnt;

void choseAlpha(int cur, int idx) {
    if (cur == k) {
        int cnt = 0;
        for (int i = 0; i < s_v.size(); i++) {
            bool isPos = true;
            for (auto c: s_v[i]) {
                if (!isUsed[c - 'a']) {
                    isPos = false;
                    break;
                }
            }
            if (isPos)
                cnt++;
        }
        max_cnt = max(max_cnt, cnt);
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;

            choseAlpha(cur + 1, i);

            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    s_v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> s_v[i];

    char arr[5] = {'a', 'n', 't', 'i', 'c'};
    for (char i : arr)
        isUsed[i - 'a'] = true;

    choseAlpha(5, 0);
    cout << max_cnt;

}

