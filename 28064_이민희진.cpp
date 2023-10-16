//
// Created by 이승철 on 2023/09/17.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MX = 105;
int n;
string arr[MX];
bool checked[MX][MX];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

bool check(string &a, string &b, int len) {
    if (a.substr(0, len) == b.substr(b.size() - len))
        return true;
    return false;
}

int sol() {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || checked[i][j] || checked[j][i])
                continue;
            string a = arr[i];
            string b = arr[j];

            int mx = min(a.size(), b.size());
            for (int len = 1; len <= mx; len++) {
                if (check(a, b, len)) {
                    checked[i][j] = checked[j][i] = true;
                    answer++;
                    break;
                }
            }
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << sol();
}