//
// Created by 이승철 on 2022/07/26.
//
#include <iostream>
#include <queue>
#include <map>

#define DATA first
#define CNT second

using namespace std;
int Task, commandCnt, value;
char Command;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Task;
    priority_queue<int, vector<int>, greater<>> min_Q;
    priority_queue<int, vector<int>, less<>> max_Q;
    map<int, int> map;
    while (Task--) {
        cin >> commandCnt;
        while (commandCnt--) {
            cin >> Command >> value;
            if (Command == 'I') {
                min_Q.push(value);
                max_Q.push(value);
                if (map.find(value) != map.end())
                    map.find(value)->CNT += 1;
                else
                    map.emplace(value, 1);
            } else if (Command == 'D') {
                if (value == 1) { // maxPQ 지울 때
                    while (!max_Q.empty() && map.find(max_Q.top())->CNT == 0)  // 이미 minPQ 에서 지워진 수들 erase
                        max_Q.pop();

                    if (!max_Q.empty()) {
                        map.find(max_Q.top())->CNT--;
                        max_Q.pop();
                    }

                } else { // minPQ 지울 때
                    while (!min_Q.empty() && map.find(min_Q.top())->CNT == 0) // 이미 max PQ 에서 지워진 수들 erase
                        min_Q.pop();

                    if (!min_Q.empty()) {
                        map.find(min_Q.top())->CNT--;
                        min_Q.pop();
                    }
                }
            }
        }

        while (!min_Q.empty() && map.find(min_Q.top())->CNT == 0) // 이미 max PQ 에서 지워진 수들 erase
            min_Q.pop();
        while (!max_Q.empty() && map.find(max_Q.top())->CNT == 0) // 이미 max PQ 에서 지워진 수들 erase
            max_Q.pop();

        if (max_Q.empty() && min_Q.empty())
            cout << "EMPTY\n";
        else
            cout << max_Q.top() << " " << min_Q.top() << '\n';

        max_Q = priority_queue<int,vector<int>,less<>>();
        min_Q = priority_queue<int,vector<int>,greater<>>();
        map.clear();
    }

}