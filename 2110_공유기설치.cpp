//
// Created by 이승철 on 2023/09/05.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, C;
vector<int> loc;

void input() {
    cin >> N >> C;
    loc.resize(N);

    for (int i = 0; i < N; i++)
        cin >> loc[i];
}

bool check(int dist) {
    int pre = loc.front();
    int cnt = 1;

    for (auto cur: loc) {
        if (cur - pre >= dist) {
            cnt++;
            pre = cur;
        }
    }
    return cnt >= C;
}

int sol() {
    int answer = 0;
    sort(loc.begin(), loc.end());

    int st = 1;
    int ed = loc.back() - loc.front();

    while (st <= ed) {
        int mid = (ed + st) / 2;
        if (check(mid)) {
            answer = max(answer, mid);
            st = mid + 1;
            continue;
        }

        ed = mid - 1;
    }
    return answer;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << sol();
}