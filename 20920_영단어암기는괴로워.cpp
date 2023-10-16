//
// Created by 이승철 on 2023/09/22.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Info{
    int cnt;
    int len;
    string str;
};

int N, M;
string word;
unordered_map<string, int> dic;
vector<Info> v;

bool cmp(Info& a, Info& b){
    if(a.cnt != b.cnt)
        return a.cnt > b.cnt;
    if(a.len != b.len)
        return a.len > b.len;
    return a.str < b.str;
}

// 등장 횟수, 길이, 알파벳 순
void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> word;
        if (word.size() < M)
            continue;

        if (dic.count(word)) {
            int cnt = dic.find(word)->second;
            dic.erase(word);
            dic.insert({word, cnt + 1});
        } else
            dic.insert({word, 1});

    }
}



void sol() {
    for (auto cur: dic)
        v.push_back({cur.second, (int)cur.first.size(), cur.first});
    sort(v.begin(), v.end(), cmp);

    for(auto cur : v)
        cout << cur.str << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();
}

