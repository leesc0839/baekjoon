#include <iostream>
#include <queue>
#include <deque>

using namespace std;
#define R first
#define C second
int board[101][101];
int currentSecond, boardSize, appleCnt, dirChangeCnt;
int snakeDir = 1;
bool eatApple;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, char>> dir_info_queue;
deque<pair<int, int>> snake_deque;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> boardSize;
    cin >> appleCnt;
    while (appleCnt--) {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = -1; // 사과 있는 곳은 -1
    }
    cin >> dirChangeCnt;
    while (dirChangeCnt--) {
        int sec;
        char dir;
        cin >> sec >> dir;
        dir_info_queue.push({sec, dir});
    }


    snake_deque.emplace_front(0, 0);
    board[0][0] = 1;

    while (!snake_deque.empty()) {

        if (!dir_info_queue.empty() && dir_info_queue.front().first == currentSecond) {
            snakeDir = (dir_info_queue.front().second == 'D') ? (snakeDir + 1) % 4 : (snakeDir - 1 + 4) % 4;
            dir_info_queue.pop();
        }
/*        cout << currentSecond << '\n';
        for (int i = 1; i <= boardSize; i++) {
            for (int c = 1; c <= boardSize; c++)
                cout << board[i][c] << " ";
            cout << '\n';
        }
        cout << '\n';*/
        auto cur = snake_deque.front();
        int nr = cur.R + dr[snakeDir];
        int nc = cur.C + dc[snakeDir];
        if (nr >= boardSize || nr < 0 || nc >= boardSize || nc < 0 || board[nr][nc] == 1) {   // 게임 끝!
            cout << currentSecond + 1;
            return 0;
        }

        // 사과가 없으면 ?
        if (board[nr][nc] != -1) {
            auto tail = snake_deque.back();
            board[tail.R][tail.C] = 0;
            snake_deque.pop_back(); // 꼬리 자르기
        }

        snake_deque.emplace_front(nr, nc);
        board[nr][nc] = 1;
        currentSecond++;
    }

}

