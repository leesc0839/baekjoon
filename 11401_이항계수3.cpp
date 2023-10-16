//
// Created by 이승철 on 2022/08/03.
//
#include <iostream>
#include <cmath>

#define P 1000000007
typedef long long ll;
using namespace std;
ll n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    ll returnValue = 1;
    for (ll i = n - m; i >= 1; i--) {
        returnValue *= i;
        returnValue %= P;
    }

    for (ll i = m; i >= 1; i--) {
        returnValue *= i;
        returnValue %= P;
    }

    for(ll i=0; i<P-2; i++)
        returnValue = returnValue * returnValue % P;

    


    for (ll i = n; i >= 1; i--) { // n!
        returnValue *= i;
        returnValue %= P;
    }

    cout<<returnValue;


}
