//
// Created by 이승철 on 2023/03/12.
//
/*
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int T, F, idx;
const int MX = 100001;
string id1, id2;
unordered_map<string, int> M;
vector<string> V[MX];

void init() {
    idx = 0;
    M.clear();
    for (auto &i: V)
        i.clear();
}

void push(string id1, string id2) {
    if (M.count(id1) && M.count(id2)) {
        int from = M.find(id2)->second;
        int to = M.find(id1)->second;
        if (from == to) {
            cout << V[from].size() << '\n';
            return;
        }

        for (auto cur: V[from]) {
            V[to].push_back(cur);
            M.erase(cur);
            M.insert({cur, to});
        }
        V[from].clear();
        cout << V[to].size() << '\n';
    } else if (M.count(id1)) {
        int from = M.find(id1)->second;
        M.insert({id2, from});
        V[from].push_back(id2);
        cout << V[from].size() << '\n';
    } else if (M.count(id2)) {
        int from = M.find(id2)->second;
        M.insert({id1, from});
        V[from].push_back(id1);
        cout << V[from].size() << '\n';
    } else {
        ++idx;
        M.insert({id1, idx});
        M.insert({id2, idx});
        V[idx].push_back(id1);
        V[idx].push_back(id2);
        cout << 2 << '\n';
    }
}

void sol() {
    cin >> T;
    while (T--) {
        init();
        cin >> F;
        for (int i = 0; i < F; i++) {
            cin >> id1 >> id2;
            push(id1, id2);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}
*/

// union - find 로 풀어보기
#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;
int t, n, idx;
string id1, id2;
unordered_map<string, int> M;
const int MX = 200002;
int root[MX], cnt[MX];

void init() {
    M.clear();
    idx = 1;
    for (int i = 0; i < MX; i++) {
        root[i] = i;
        cnt[i] = 1;
    }
}

int find(int x) {
    if (x == root[x])
        return x;
    return root[x] = find(root[x]);
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        root[x] = y;
        cnt[y] += cnt[x];
        cnt[x] = 1;
    }
    return cnt[y];
}

void sol() {
    cin >> t;
    while (t--) {
        init();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> id1 >> id2;
            if (M[id1] == 0)
                M[id1] = idx++;
            if (M[id2] == 0)
                M[id2] = idx++;
            cout << merge(M[id1], M[id2]) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}

