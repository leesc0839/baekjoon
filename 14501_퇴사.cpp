#include <iostream>
#include <algorithm>

using namespace std;
int n, max_profit; // 1~15
int board[25][2]; // 날짜 : 1~5, 급여 : 1~1000
int profit[25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int r = 1; r <= n; r++) {
        for (int c = 0; c < 2; c++) {
            int elem;
            cin >> elem;
            if (c == 0)  // 날짜
                board[r][0] = r + elem;
            else if (c == 1) { // 급여
                board[r][1] = elem;
                profit[r] = elem;
            }

        }
    }

    for (int cur = 1; cur <= n; cur++) {
        int profit_tmp = 0;
        for (int prev = 1; prev < cur; prev++) {// 현재 날짜를 지나 치지 않는 수들 중 가장 이익이 큰 값
            if (board[prev][0] <= cur)
                profit_tmp = max(profit_tmp, profit[prev]);
        }
        profit[cur] += profit_tmp;
    }

    for (int i = 1; i <= n; i++) {
        if (board[i][0] > n+1)
            continue;
        max_profit = max(max_profit, profit[i]);
    }
    cout << max_profit;
}