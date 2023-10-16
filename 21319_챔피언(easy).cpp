//
// Created by 이승철 on 2023/09/23.
//

#include <iostream>
#include <vector>

using namespace std;

const int MX = 200005;
int N, arr[MX];
vector<pair<int, int>> chp;

void input() {
    cin >> N;
    if (N == 1) {
        cout << 1;
        exit(0);
    }
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 2; i <= N; i++) {
        if (arr[i - 1] < arr[i])
            chp.emplace_back(i, arr[i]);
    }
}

bool check(int idx) {
    int pw = chp[idx].second + chp[idx].first - 1;

    for (int i = idx + 1; i < chp.size(); i++) {
        int n_pw = pw + chp[i].first - chp[idx].first - 1;
        if (n_pw <= chp[i].second)
            return false;
    }
    return true;
}

void sol() {
    int st = 0;
    int ed = chp.size() - 1;
    while (st < ed) {
        int mid = (st + ed) / 2;
        if (check(mid))
            ed = mid;
        else
            st = mid + 1;
    }

    if (chp.empty()) {
        cout << -1;
        return;
    }

    for (int i = st; i < chp.size(); i++)
        cout << chp[i].first << ' ';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();
}