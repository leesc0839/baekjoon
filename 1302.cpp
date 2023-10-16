//
// Created by 이승철 on 2022/07/10.
//
// Created by 이승철 on 2022/07/10.
//

#include <iostream>
#include <map>

using namespace std;

int N;
int maxCnt;
string book;
string returnValue;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, int> tmp;
    cin >> N;
    while (N--) {
        cin >> book;
        if (book == tmp.find(book)->first) {
            tmp.find(book)->second++;
            continue;
        }
        tmp.insert({book, 1});
    }

    for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {

        if (iter->second > maxCnt) {
            maxCnt = iter->second;
            returnValue = iter->first;
        }
    }
    cout << returnValue;
}



/*
#include <iostream>
#define name second
#define cnt first
using namespace std;

pair<int, string> tmp[1001];
long long max_cnt;
long long max_idx;
long long cur_idx;
string book;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) {
        cin >> book;

        for (int i = 0; i < book.length(); i++) {
            long long c = book[i] - 'a';
            for (int j = 0; j < i; j++) {
                c*=26;
            }
            cur_idx += c;
        }
        cur_idx %= 1001;
        tmp[cur_idx].name = book;
        ++tmp[cur_idx].cnt;

        if (max_cnt < tmp[cur_idx].cnt) {
            max_cnt = tmp[cur_idx].cnt;
            max_idx = cur_idx;
        } else if (max_cnt == tmp[cur_idx].cnt) {
            if ((tmp[max_idx].name) > (tmp[cur_idx].name))
                max_idx = cur_idx;
        }
        cur_idx = 0;
    }
    cout << tmp[max_idx].name;

}*/
