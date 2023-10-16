//
// Created by 이승철 on 2023/09/17.
//

#include <iostream>

using namespace std;
const int MX = 10;
int ans[MX], arr[MX], answer;

bool check(int idx) {
    if (arr[idx] == arr[idx - 1] && arr[idx - 1] == arr[idx - 2] && arr[idx] == arr[idx - 2])
        return true;
    return false;
}

void sol(int cnt, int score) {
    if (cnt == MX) {
        if (score >= 5)
            answer++;
        return;
    }

    for (int i = 1; i <= 5; i++) {
        arr[cnt] = i;
        if (cnt > 1 && check(cnt))
            continue;
        sol(cnt + 1, score + (ans[cnt] == i));
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int &cur: ans)
        cin >> cur;
    sol(0, 0);
    cout << answer;
}