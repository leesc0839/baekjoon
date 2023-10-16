//
// Created by 이승철 on 2023/09/14.
//
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
int N;
ll tmp;
unordered_map<ll, int> m;

ll sol() {
    ll answer;
    int cnt = 0;

    cin >> N;
    while (N--) {
        cin >> tmp;
        if (!m.count(tmp))
            m.insert({tmp, 1});
        else
            m.find(tmp)->second += 1;
        
        int cur =
        if (cnt < cur) {
            cnt = cur;
            answer = tmp;
        }

    }
    return answer;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << sol();
}
