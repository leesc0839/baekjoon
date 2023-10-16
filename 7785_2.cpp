//
// Created by 이승철 on 2022/07/10.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string>v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string name, command;
    while (N--) {
        cin >> name >> command;

        if (command == "enter") {
            v.push_back(name);
        } else if (command == "leave") {
            auto c = binary_search(v.begin(), v.end(), name);
            v.erase(v.begin()+c);
        }
    }
    std::sort(v.begin(), v.end());
    for(int i = v.size()-1; i>=0; i--){
        cout<<v[i]<<'\n';
    }

}
