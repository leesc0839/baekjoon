//
// Created by 이승철 on 2022/07/25.
//
#include <iostream>
#include <string>

using namespace std;
int t, n;
string ans = "YES";
#define number 10
#define MAX 11
using namespace std;

class Trie {
private:
    Trie *next[number];
    bool finished;

public:
    Trie() {
        fill(next, next + number, nullptr);
        finished = false;
    }

    ~Trie() {
        for (int i = 0; i < number; i++) {
            if (next[i])
                delete next[i];
        }
    }

    void insert(char *key, bool isSame) { // char 배열을 받음.
        if (*key == '\0') { // '/0' 을 만나면 null 로 인식
            finished = true;
            if (isSame)  // 지금 까지 온 루트가 이미 있는 루트 인 경우 ex) 91125 -> 911
                ans = "NO";
            return;
        }
        int nextIdx = *key - '0'; // char -> int
        if (!next[nextIdx]) { // 다음 노드가 없을 때 새로 개척
            next[nextIdx] = new Trie();
            next[nextIdx]->insert(key + 1, false);
        } else if (next[nextIdx]->finished) { // 다음 노드가 이미 있고, 자신 보다 짧은 숫자, 이미 finished 된 숫자가 있는 상황
            next[nextIdx]->insert(key + 1, true);
            ans = "NO"; // ex ) 911이 들어 오고 91125가 들어 왔을 때
        } else // 다음 노드가 이미 있는 상황
            next[nextIdx]->insert(key + 1, true);


    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        Trie *root = new Trie();
        cin >> n;
        while (n--) {
            char phoneNumber[MAX];
            cin >> phoneNumber;
            root->insert(phoneNumber, true);
        }
        cout << ans << '\n';
        ans = "YES";
    }
}