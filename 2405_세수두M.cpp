//
// Created by 이승철 on 2022/08/01.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int elem, a, b, c, mean, median, returnValue;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        v.emplace_back(elem);
    }
    v.reserve(n);
    std::sort(v.begin(), v.end()); // log n

    for (int i = 1; i < v.size() - 1; i++) {
        //a == b 기준 바로 앞 , c == 맨 뒤  => 중위 값 기준 평균이 가장 클 수 있는 경우
        b = v[i];
        a = v[i - 1];
        c = v[v.size() - 1];

        returnValue = max(returnValue, (a - 2 * b + c));


        //a == 가장 앞, c== b 바로 뒤

        b = v[i];
        a = v[0];
        c = v[i + 1];

        returnValue = max(returnValue, 3 * b - (a + b + c));

    }

    cout << returnValue;

}
