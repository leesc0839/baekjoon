//
// Created by 이승철 on 2023/03/10.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define HOUSE 1
#define SHOP 2
#define FESTIVAL 3

using namespace std;
struct vertex {
    int r;
    int c;
    int info;
};

int t, n, r, c;
const int MX = 103;
bool visit[MX], flag;
vector<vertex> V;

void dfs(int idx, int bottle) {
    if (V[idx].info == FESTIVAL) {
        flag = true;
        return;
    }

    for (int nxt = 0; nxt < n + 2; nxt++) {
        int dist = abs(V[idx].r - V[nxt].r) + abs(V[idx].c - V[nxt].c);
        if (flag)
            return;
        if (visit[nxt] || bottle * 50 < dist)
            continue;
        visit[nxt] = true;
        if (V[nxt].info == SHOP)
            dfs(nxt, 20);
        else
            dfs(nxt, bottle - ((dist - 1) / 50 + 1));
    }
}

void init() {
    V.clear();
    memset(visit, false, sizeof(visit));
    visit[0] = true;
    flag = false;
}

void sol() {
    cin >> t;
    while (t--) {
        init();
        cin >> n;
        //house
        cin >> r >> c;
        V.push_back({r, c, HOUSE});
        //shop
        for (int i = 1; i <= n; i++) {
            cin >> r >> c;
            V.push_back({r, c, SHOP});
        }
        //festival
        cin >> r >> c;
        V.push_back({r, c, FESTIVAL});
        //dfs
        dfs(0, 20);
        flag ? cout << "happy\n" : cout << "sad\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}

