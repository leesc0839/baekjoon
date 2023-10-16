//
// Created by 이승철 on 2023/09/14.
//
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;
const int MX = 55;
int N;
string arr[MX];

int count(string &a) {
    int sum = 0;
    for (char c: a) {
        if (isdigit(c))
            sum += c - '0';
    }
    return sum;
}

bool cmp(string &a, string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    if (count(a) != count(b))
        return count(a) < count(b);
    return a < b;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void sol() {
    sort(arr, arr + N, cmp);
    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}

