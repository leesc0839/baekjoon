//
// Created by 이승철 on 2022/09/29.
//
#include <iostream>

using namespace std;
char tooth[6][10];
int K, g, dir, ans;
pair<int, int> gear_idx[6];
bool is_same_tooth[5];

void check_same() {
    for (int gear = 1; gear < 4; gear++) {
        if (tooth[gear][gear_idx[gear].second] == tooth[gear + 1][gear_idx[gear + 1].first])
            is_same_tooth[gear] = true;
        else
            is_same_tooth[gear] = false;
    }
}

void tool(int gear, int dir) {
    if (dir == 1) {
        gear_idx[gear].first = (gear_idx[gear].first + 7) % 8;
        gear_idx[gear].second = (gear_idx[gear].second + 7) % 8;
    } else {
        gear_idx[gear].first = (gear_idx[gear].first + 1) % 8;
        gear_idx[gear].second = (gear_idx[gear].second + 1) % 8;
    }
}

void rotate(int gear, int direction) {
    check_same();
    // 오른쪽 방향
    int cur_gear = gear;
    int nxt_gear = gear + 1;
    int cur_gear_dir = direction;

    while (true) {
        if (nxt_gear > 4 || is_same_tooth[cur_gear]) {
            tool(cur_gear, cur_gear_dir);
            break;
        } else
            tool(cur_gear, cur_gear_dir);

        cur_gear_dir = (cur_gear_dir == -1) ? 1 : -1;
        cur_gear = nxt_gear;
        nxt_gear = cur_gear + 1;
    }

    //왼쪽 방향
    cur_gear = gear;
    nxt_gear = gear - 1;
    cur_gear_dir = direction;

    while (true) {
        if (nxt_gear < 1 || is_same_tooth[nxt_gear]) {
            if (cur_gear != gear)
                tool(cur_gear, cur_gear_dir);
            break;
        } else {
            if (cur_gear != gear)
                tool(cur_gear, cur_gear_dir);
        }

        cur_gear_dir = (cur_gear_dir == -1) ? 1 : -1;
        cur_gear = nxt_gear;
        nxt_gear = cur_gear - 1;
    }
}

void sol() {
    for (int gear = 1; gear <= 4; gear++) {
        for (int t = 0; t < 8; t++)
            cin >> tooth[gear][t];
    }

    for (int gear = 1; gear <= 4; gear++)
        gear_idx[gear] = {6, 2}; // 왼쪽, 오른쪽

    cin >> K;
    while (K--) {
        cin >> g >> dir;
        rotate(g, dir);
    }

    for (int gear = 1; gear <= 4; gear++) {
        if (tooth[gear][(gear_idx[gear].second + 6) % 8] == '1') {
            if (gear == 1)
                ans += 1;
            else if (gear == 2)
                ans += 2;
            else if (gear == 3)
                ans += 4;
            else
                ans += 8;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}
