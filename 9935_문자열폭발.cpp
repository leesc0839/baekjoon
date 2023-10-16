//
// Created by 이승철 on 2022/07/27.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
string cmd;
string bomb;
int prefixIdx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> cmd;
    cin >> bomb;
    stack<pair<char, int>> s;

    for (auto c: cmd) {
        if (c == bomb[0]) {
            s.push({c, 0});
            prefixIdx = s.top().second;
        } /*else if (!s.empty() && (c == bomb[prefixIdx])) {
            s.push({c, s.top().second});
            prefixIdx = s.top().second;
        }*/ else if (!s.empty() && (c == bomb[prefixIdx + 1])) {
            s.push({c, prefixIdx + 1});
            prefixIdx = s.top().second;
        } else{
            s.push({c, -1});
            prefixIdx = 0;
        }


        if (!s.empty() && (s.top().second == bomb.size()-1)) {
            for (int i = 0; i < bomb.size(); i++){
                if(!s.empty())
                    s.pop();
                else
                    break;
            }
        }
        if (!s.empty())
            prefixIdx = s.top().second;
    }
    if (s.empty())
        cout << "FRULA\n";
    else {
        vector<char> return_v;
        return_v.reserve(s.size());
        while (!s.empty()) {
            return_v.push_back(s.top().first);
            s.pop();
        }
        for(auto iter = return_v.rbegin(); iter!=return_v.rend(); iter++)
            cout<<*iter;
    }
}
