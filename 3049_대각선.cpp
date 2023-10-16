//
// Created by 이승철 on 2022/07/30.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define K 4
using namespace std;
int N;
vector<int> v;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    if(N>=4){
        for (int i = 0; i < 4; i++)
            v.emplace_back(1);
        for (int i = 0; i < N - 4; i++)
            v.emplace_back(0);
        std::sort(v.begin(), v.end());
        do {
            cnt++;
        } while (next_permutation(v.begin(), v.end()));
        cout << cnt;
    }else{
        cout<<0;
    }

}