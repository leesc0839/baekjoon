//
// Created by 이승철 on 2022/07/26.
//
#include <iostream>
#include <list>
#include <set>

using namespace std;
string cmd;
string bomb;
bool isBomb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<char> cmd_list;
    cin >> cmd;
    cin >> bomb;
    for (auto c: cmd)
        cmd_list.emplace_back(c);

    auto startIter = cmd_list.begin();
    auto endIter = cmd_list.begin();
    int i = 0;
    while (true) {
        int beforeSize = (int) cmd_list.size();

        for (auto iter = cmd_list.begin(); iter != cmd_list.end(); iter++) {
            if (bomb[i] == *iter) {
                isBomb = true;
                // 첫 번째 문자 일치할 때
                if (bomb[0] == *iter)
                    startIter = iter;
                // 마지막 문자 일치할 때
                if (isBomb && bomb[bomb.length() - 1] == *iter) {
                    endIter = ++iter;
                    cmd_list.erase(startIter, endIter);
                    i = 0;
                    isBomb = false;
                    continue;
                    // endIter 앞까지 삭제 해줘서
                }
                //그 외
                i++;

            } else {
                if (bomb[0] == *iter) { // 폭탄 문자의 첫 글자가 연속 으로 2개가 나왔을 때
                    isBomb = true;
                    startIter = iter;
                    i = 1;
                }else{
                    isBomb = false;
                    i = 0;
                }
            }
        }
        if (cmd_list.empty() || beforeSize == cmd_list.size())
            break;
    }

    if (cmd_list.empty())
        cout << "FRULA";
    else {
        for (auto iter = cmd_list.begin(); iter != cmd_list.end(); iter++)
            cout << *iter;
    }


}
