//
// Created by 이승철 on 2022/07/23.
//
#include <iostream>
#include <list>

using namespace std;
string s;
int M;
char c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> list;
    cin >> s >> M;
    for(auto i : s)
        list.push_back(i);
    auto cur = list.end();
    while (M--) {
        cin >> c;
        if (c == 'L') {
            if (cur != list.begin())
                cur--;
        } else if (c == 'D') {
            if (cur != list.end())
                cur++;
        } else if (c == 'B') {
            if(!list.empty() && cur != list.begin()){
                cur--;
                cur = list.erase(cur);
            }
        } else if (c == 'P') {
            cin >> c;
            list.insert(cur, c);
        }
    }

    for(auto i : list)
        cout << i;


}

