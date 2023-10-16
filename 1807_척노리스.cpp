//
// Created by 이승철 on 2023/09/23.
//

#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
string str;
int suffix[3] = {2, 0, 2};

void sol() {
    ll num = 0;
    while (str.size() < pow(10, 8)) {
        for (int i = 0; i < 4; i++) {
            num++;
            if (i == 3) {
                str += to_string(num);
                continue;
            }
            str += to_string(num);
            str += to_string(suffix[i]);
        }
    }
    cout << num;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll num = 1;
    sol();
    while (num) {
        cin >> num;
        cout << str[num - 1] << '\n';
    }
}

