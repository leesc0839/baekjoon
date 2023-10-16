//
// Created by 이승철 on 2022/08/08.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int N, elem, strike, ball, rtn_cnt;
bool isUsed[10];
vector<int> cur_elem;
map<int, int> M;

int checkStrike(int e) {
    int rtn = 0;
    for (int i = 2; i >= 0; i--) {
        if (e % 10 == cur_elem[i])
            rtn++;
        e /= 10;
    }
    return rtn;
}

int checkBall(int e) {
    int rtn = 0;
    vector<int> tmp = cur_elem;
    std::sort(tmp.begin(), tmp.end());
    for (int i = 2; i >= 0; i--) {
        if ((e % 10 != cur_elem[i]) && binary_search(tmp.begin(), tmp.end(), e % 10))
            rtn++;
        e /= 10;
    }
    return rtn;
}

void check(int cnt) {
    if (cnt == 3) {
        if (checkStrike(elem) == strike && checkBall(elem) == ball) {
            int cur_e = (cur_elem[0] * 100) + (cur_elem[1] * 10) + cur_elem[2];
            if (M.count(cur_e))
                M.find(cur_e)->second++;
            else
                M.emplace(cur_e, 1);
        }
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            cur_elem[cnt] = i;

            check(cnt + 1);

            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cur_elem.resize(3);
    for (int i = 0; i < N; i++) {
        cin >> elem >> strike >> ball;
        fill(isUsed, isUsed + 10, false);
        check(0);
    }
    for (auto c: M) {
        if (c.second == N)
            rtn_cnt++;
    }
    cout << rtn_cnt << '\n';

}
