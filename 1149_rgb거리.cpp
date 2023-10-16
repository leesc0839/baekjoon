//
// Created by 이승철 on 2022/08/14.
//
#include <iostream>

using namespace std;
int n;
int cost[1001][3];
int min_cost[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    }

    min_cost[0][0] = cost[0][0];
    min_cost[0][1] = cost[0][1];
    min_cost[0][2] = cost[0][2];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0)
                min_cost[i][0] = min(min_cost[i - 1][1], min_cost[i - 1][2]) + cost[i][0];
            else if (j == 1)
                min_cost[i][1] = min(min_cost[i - 1][0], min_cost[i - 1][2]) + cost[i][1];
            else if (j == 2)
                min_cost[i][2] = min(min_cost[i - 1][0], min_cost[i - 1][1]) + cost[i][2];
        }
    }
    int arr[3] = {min_cost[n][0],min_cost[n][1],min_cost[n][2]};
    sort(arr, arr+3);
    cout << arr[0];

}
