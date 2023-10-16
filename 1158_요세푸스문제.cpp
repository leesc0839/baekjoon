//
// Created by 이승철 on 2022/07/23.
//
#include <iostream>
#include <list>

using namespace std;
int N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    list<int> list;
    for (int i = 0; i < N; i++)
        list.push_back(i + 1);
    auto iter = list.begin();
    cout << "<";
    while (N--) {
        for (int i = 0; i < K - 1; i++) {
            ++iter;
            if (iter == list.end())
                iter = list.begin();
        }
        if (list.size() == 1)
            cout << *iter;
        else
            cout << *iter << ", ";
        iter = list.erase(iter);
        if (iter == list.end())
            iter = list.begin();
    }

    cout << '>';

}
