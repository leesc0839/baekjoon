//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>
using namespace std;
int N;
int two, five;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int idx = i;
        while (idx % 2 == 0) {
            idx /= 2;
            two++;
        }

        while (idx % 5 == 0) {
            idx /= 5;
            five++;
        }
    }
    cout<<min(two,five);
}
