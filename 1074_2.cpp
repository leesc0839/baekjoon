//
// Created by 이승철 on 2022/07/18.
//

#include <iostream>
#include <cmath>

using namespace std;
int dr[5] = {0,0, 1, 0, -1};
int dc[5] = {0,1, -1, 1, 1};

int curNum, curR, curC;
int N, R, C;
int range;

void moveBoard(int r, int c, int n) {
    if (r == R && c == C)
        return;
    range = (int) pow(2, n - 1);
    while (true) {
        for (int i = 0; i < 4; i++) {
            if (r == R && c == C)
                return;
            curR += dr[i];
            curC += dc[i];
            ++curNum;
        }
        if (curC >= range) {
            curR += 2;
            curC -= range;
        }
    }
}

int moveBoard2(int r, int c, int visit, int n){
    range = (int) pow(2, n - 1);
    if (r == R && c == C) // base condition
        return visit;

    for (int i = 1; i <= 4; i++) {
        r += dr[i];
        c += dc[i];
        if (r == R && c == C)
            return visit + i;
    }
    if(c >= range){

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R >> C;

    range = (int) pow(2, N - 1);

    bool isRight = (C >= range);
    bool isDown = (R >= range);

    if (isRight) C -= range;
    if (isDown) R -= range;

    if (isRight && isDown) {
        curNum += 3 * range * range;
    } else if (isRight) {
        curNum += range * range;
    } else if (isDown) {
        curNum += 2 * range * range;
    }
    cout << moveBoard2(0, 0, 0, 1) + curNum;
}
