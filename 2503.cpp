//
// Created by 이승철 on 2023/07/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

#define MAX 987
#define MIN 123

struct Info {
    int num;
    int st;
    int ball;
};

using namespace std;
int N, num, st, ball;
vector<Info> hint;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num >> st >> ball;
        hint.push_back({num, st, ball});
    }
}

map<int, int> make_map(int number) {
    map<int, int> m;
    for (int i = 0; i < 3; i++) {
        m.insert({number % 10, i});
        number /= 10;
    }

    return m;
}

bool count(int brute, Info info) {
    map<int, int> m = make_map(info.num);
    int st = 0;
    int b = 0;

    for (int i = 0; i < 3; i++) {
        int key = brute % 10;
        brute /= 10;

        if (m.count(key) && m.find(key)->second == i) {
            st++;
            continue;
        }

        if (m.count(key))
            b++;
    }

    return (info.st == st && info.ball == b);
}

bool check(int brute) {
    for (Info cur: hint) {
        if (!count(brute, cur))
            return false;
    }
    return true;
}

bool is_valid_brute(int brute) {
    set<int> s;
    for (int i = 0; i < 3; i++) {
        s.insert(brute % 10);
        brute /= 10;
    }

    if (s.count(0))
        return false;
    if (s.size() != 3)
        return false;

    return true;
}

int sol() {
    int ret = 0;
    for (int brute = MIN; brute <= MAX; brute++) {
        if (is_valid_brute(brute) && check(brute))
            ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << sol();
}

