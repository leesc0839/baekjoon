//
// Created by 이승철 on 2022/08/08.
//
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, bool>> v;
int arr[21];
int n, s, rtn_cnt;

void func(int cnt, int cur, int idx) {
    if (cnt == cur) {
        int sum = 0;
        for (int i = 0; i < cnt; i++)
            sum += arr[i];
        if (sum == s)
            rtn_cnt++;


        return;
    }
    for (int i = idx; i < n; i++) {
        if (!v[i].second) {
            v[i].second = true;
            arr[cur] = v[i].first;
            func(cnt, cur + 1,i);
            v[i].second = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = false;
    }
    for (int i = 1; i <= n; i++) {
        func(i, 0, 0);
    }
    cout << rtn_cnt;
}

