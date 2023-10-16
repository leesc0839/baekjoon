//
// Created by 이승철 on 2022/08/06.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, op;
int elem_arr[101];
int op_arr[100];
vector<pair<int, bool>> op_v;
int rtn_max = -1000000000;
int rtn_min = 1000000000;

void shuffle(int c) {
    if (c == n - 1) {
        int rtn_val = elem_arr[0];
        for (int i = 0; i < n - 1; i++) {
            if (op_arr[i] == 1)
                rtn_val += elem_arr[i + 1];
            else if (op_arr[i] == 2)
                rtn_val -= elem_arr[i + 1];

            else if (op_arr[i] == 3)
                rtn_val *= elem_arr[i + 1];

            else if (op_arr[i] == 4)
                rtn_val /= elem_arr[i + 1];
        }
        rtn_max = max(rtn_val, rtn_max);
        rtn_min = min(rtn_val, rtn_min);
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (!op_v[i].second) {
            op_arr[c] = op_v[i].first;
            op_v[i].second = true;

            shuffle(c + 1);

            op_v[i].second = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> elem_arr[i];


    for (int i = 0; i < 4; i++) {
        cin >> op;
        if (i == 0) {
            while (op--)
                op_v.emplace_back(1, false);
        } else if (i == 1) {
            while (op--)
                op_v.emplace_back(2, false);
        } else if (i == 2) {
            while (op--)
                op_v.emplace_back(3, false);
        } else if (i == 3) {
            while (op--)
                op_v.emplace_back(4, false);
        }
    }
    shuffle(0);
    cout <<rtn_max << '\n' << rtn_min;
}
