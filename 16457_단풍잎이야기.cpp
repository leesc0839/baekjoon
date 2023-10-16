//
// Created by 이승철 on 2022/08/05.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, k, rtn_cnt;
vector<vector<int>> quest_v;
vector<int> key_v;

void makeKeySet(int cnt, int cur) {
    if (cnt == n) {
        int cur_cnt = 0;
        for (int i = 0; i < m; i++) {
            bool isClear = true;
            for (int j = 0; j < k; j++) {
                if (!binary_search(key_v.begin(), key_v.end(), quest_v[i][j])) {
                    isClear = false;
                    break;
                }
            }
            if (isClear)
                cur_cnt++;
        }
        rtn_cnt = max(rtn_cnt, cur_cnt);
        return;
    }
    for (int i = cur; i <= 2 * n; i++) { // cur 부터 시작 cur+1을 저장 해서 넘겨줌.
        key_v.emplace_back(i);

        makeKeySet(cnt + 1, i + 1);

        key_v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    quest_v.resize(m + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            int elem;
            cin >> elem;
            quest_v[i].emplace_back(elem);
        }
    }
    makeKeySet(0, 1);
    cout << rtn_cnt;
}

