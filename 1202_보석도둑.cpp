//
// Created by 이승철 on 2023/03/23.
//
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;
/*
 * N 보석 : 1 ~ 300,000
 * K 가방 : 1 ~ 300,000
 * M 무게 : 0 ~ 1,000,000
 * V 가격 : 0 ~ 1,000,000
 */
int N, K, M, V, C, ret, cur;
vector<int> bg;
vector<pair<int, int>> it;
stack<int> bag;
stack<pair<int, int>> item;
multimap<int, int> trash;

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> M >> V;
        it.emplace_back(M, V);
    }
    for (int i = 0; i < K; i++) {
        cin >> C;
        bg.emplace_back(C);
    }
}

void init() {
    sort(it.begin(), it.end());
    sort(bg.begin(), bg.end());

    for (auto iter = it.rbegin(); iter != it.rend(); iter++)
        item.push(*iter);
    for (auto iter = bg.rbegin(); iter != bg.rend(); iter++)
        bag.push(*iter);
}

void pop() {
    while (true) {
        if (bag.empty())
            break;
        if (item.empty()) {
            for (int i = 0; i < bag.size(); i++) {
                if (trash.empty())
                    break;
                auto iter = trash.upper_bound(bag.top());
                iter--;
                int value = iter->second;
                ret += value;
                trash.erase(iter->first);
            }
            return;
        }
        int bag_lim = bag.top();
        int item_lim = item.top().first;
        int item_val = item.top().second;

        // fix
        if (bag_lim < item_lim) {
            if (!trash.empty()) {
                auto iter = trash.upper_bound(bag_lim);
                iter--;
                pair<int, int> mx;
                for (; iter != trash.begin(); iter--) {
                    if (cur < iter->second)
                        mx = {iter->first, iter->second};
                }
                if (cur < trash.begin()->second)
                    mx = {iter->first, iter->second};
                cur = mx.second;
                trash.erase(mx.first);
            }
            ret += cur;
            cur = 0;
            bag.pop();
            continue;
        }

        // can push
        if (cur <= item_val) { // <= or < 333 넣어서 생각
            cur = item_val;
            if (!trash.empty()) {
                auto iter = trash.upper_bound(bag_lim);
                iter--;
                pair<int, int> mx;
                for (; iter != trash.begin(); iter--) {
                    if (cur < iter->second)
                        mx = {iter->first, iter->second};
                }
                if (cur < trash.begin()->second)
                    mx = {iter->first, iter->second};
                cur = mx.second;
                trash.erase(mx.first);
            }
            trash.insert({item_lim, item_val});
            item.pop();
        } else {
            trash.insert({item_lim, item_val});
            item.pop();
        }
    }
}

void sol() {
    pop();
    cout << ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
}

