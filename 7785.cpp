//
// Created by 이승철 on 2022/07/10.
//
#include <iostream>
#include <map>

using namespace std;
string name, command;
map<string, int> tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) {
        cin >> name >> command;
        if (tmp.find(name)->first == name) {
            tmp.erase(name);
        } else {
            tmp.insert({name, 1});
        }
    }

    for(auto iter = tmp.rbegin(); iter!=tmp.rend(); iter++){
        cout<<iter->first<<'\n';
    }

}
