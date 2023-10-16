//
// Created by 이승철 on 2022/07/24.
//
#include <iostream>
#include <list>

using namespace std;
int T, arrSize, num;
char dummy;
string command;

bool isReverseMode;
bool isError;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        list<int> list;
        cin >> command;
        cin >> arrSize;
        while (true) {
            cin >> dummy;
            if (dummy == ']')
                break;
            if (arrSize == 0) {
                cin >> dummy; // 0이어도 [ ]입력은 받아야 하니까 !
                break;
            }
            cin >> num;
            list.push_back(num);
        }

        for (char c: command) {
            if (c == 'D' && list.empty()) {
                isError = true;
                break;
            } else if (c == 'R' && isReverseMode)
                isReverseMode = false;
            else if (c == 'R' && !isReverseMode)
                isReverseMode = true;
            else if (c == 'D' && isReverseMode)
                list.pop_back();
            else if (c == 'D' && !isReverseMode)
                list.pop_front();
        }

        if (isError)
            cout << "error\n";
        else if (isReverseMode) {
            cout << '[';
            while (list.size() > 1) {
                cout << list.back() << ",";
                list.pop_back();
            }
            if (!list.empty()) { // size 0 일 때 커맨드가 R 일 때 예외 처리
                cout << list.back();
                list.pop_back();
            }
            cout << "]\n";
        } else {
            cout << '[';
            while (list.size() > 1) {
                cout << list.front() << ",";
                list.pop_front();
            }
            if (!list.empty()) { // size 0 일 때 커맨드가 R 일 때 예외 처리
                cout << list.front();
                list.pop_front();
            }
            cout << "]\n";
        }
        isReverseMode = isError = false;
    }
}

