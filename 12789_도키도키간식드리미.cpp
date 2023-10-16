//
// Created by 이승철 on 2022/07/23.
//
#include <iostream>
#include <stack>

using namespace std;
int N, ticket;
int current = 1;
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> ticket;
        if (current == ticket)
            current++;
        else {
            if (!S.empty() && S.top() < ticket ) {
                cout << "Sad";
                return 0;
            } else
                S.push(ticket);
        }

        if(!S.empty() && S.top() == current){
            while(!S.empty() && current == S.top()){
                S.pop(); ++current;
            }
        }
    }
    cout << "Nice";
}

