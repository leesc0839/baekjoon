//
// Created by 이승철 on 2022/07/31.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;
ll TK, num, nonLoopNum, den;
string s;
bool loopMode;
vector<ll> v;
vector<ll> nonLoopV;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> TK;
    while (TK--) {
        cin >> s;
        for (ll i = 0; i < s.size(); i++) {
            if (i == 0 || i == 1 || s[i] == ')')
                continue;
            if (s[i] == '(')
                loopMode = true;
            else if (!loopMode) {
                v.push_back(s[i] - '0');
                nonLoopV.push_back(s[i] - '0');
            } else if (loopMode)
                v.push_back(s[i] - '0');
        }

        ll idx = (ll) v.size() - 1;

        for (auto c: v) {
            num += c * (ll) pow(10, idx);
            idx--;
        }

        if (!loopMode)
            den = (ll) pow(10, v.size());
        else {
            den = (ll) pow(10, v.size()) - (ll) pow(10, nonLoopV.size());
            ll idx2 = (ll) nonLoopV.size() - 1;
            for (auto c: nonLoopV) {
                nonLoopNum += c * (ll) pow(10, idx2);
                idx2--;
            }
            num -= nonLoopNum;
        }
        while (true) {
            if (gcd(num, den) == 1)
                break;
            ll g = gcd(den, num);
            num /= g;
            den /= g;
        }
        cout << num << '/' << den << '\n';
        num = nonLoopNum = den = 0;
        v.clear();
        nonLoopV.clear();
        loopMode = false;
    }

}
