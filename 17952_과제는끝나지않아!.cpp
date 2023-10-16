//
// Created by 이승철 on 2022/07/24.
//
#include <iostream>
#include <stack>
#define Score first
#define Minute second
using namespace std;
int N, homework, score, minute;
int resultValue;
stack<pair<int, int>> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> homework;
        if (homework == 1) {
            cin >> score >> minute;
            S.push({score, minute - 1});
        } else {
            if (!S.empty())
                S.top().Minute--;
        }
        if (!S.empty() && S.top().Minute == 0) {
            resultValue += S.top().Score;
            S.pop();
        }
    }
    cout << resultValue;

}

