//
// Created by 이승철 on 2022/08/01.
//
#include <iostream>

using namespace std;
int TK, x, y, cur_sum, cur_idx, cur_data;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> TK;
    while (TK--) {
        cin >> x >> y;
        while (true) {
            cur_data++;
            cur_sum += cur_data;
            cur_idx++;
            if (2 * cur_sum + cur_data == y - x) {
                cout << 2 * cur_idx + 1 << '\n';
                break;
            }
            if (2 * cur_sum + cur_data + 1 == y - x) {
                cout << 2 * cur_idx + 1 << '\n';
                break;
            }
        }
        cur_sum = cur_idx = 0;
        cur_data = 1;
    }
}

