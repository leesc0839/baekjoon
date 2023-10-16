//
// Created by 이승철 on 2022/07/10.
//
#include <iostream>

int arr[1001];
int cur;
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << cur + 1 << " ";
    int move = arr[cur];
    arr[cur] = 0;

    for (int i = 0; i < N - 1; i++) {
        if (move < 0) {
            move = -1 * move;
            while (move--) {
                cur = (cur - 1 + N) % N;
                if (arr[cur] == 0)
                    move++;
            }

        } else {
            while (move--) {
                cur = (cur + 1) % N;
                if (arr[cur] == 0)
                    move++;
            }
        }
        move = arr[cur];
        arr[cur] = 0;
        cout << cur + 1 << " ";
    }
}

