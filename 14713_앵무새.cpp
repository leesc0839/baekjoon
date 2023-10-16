//
// Created by 이승철 on 2022/07/24.
//
#include <iostream>
#include <map>
#include <sstream>

#define lineNum first
#define idx second

using namespace std;
int N, cnt;
string line, word;
int curIndexOfWord[101];
int wordCnt;

int main() {
    map<string, pair<int, int>> map;
    cin >> N;
    cin.ignore(); // 개행 무시 !
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream ss(line);
        ss.str(line);
        while (ss >> word) {
            map.insert({word, {i, cnt++}});
        }
        cnt = 0;
    }
    getline(cin, line);
    stringstream ss(line);
    ss.str(line);
    while (ss >> word) {
        if (!map.count(word)) {
            cout << "Impossible";
            return 0;
        } else {
            int idxOfWord = map.find(word)->second.idx;
            int idxOfBird = map.find(word)->second.lineNum;
            if (idxOfWord != curIndexOfWord[idxOfBird]) {
                cout << "Impossible" << '\n';
                return 0;
            }
            curIndexOfWord[idxOfBird]++;
            wordCnt++;
        }
    }
    if (map.size() == wordCnt)
        cout << "Possible";
    else
        cout << "Impossible";
}

