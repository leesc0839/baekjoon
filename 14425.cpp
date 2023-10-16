//
// Created by 이승철 on 2022/07/25.
//
#include <iostream>
#include <string>
#include <cstring>

#define alphabet 26
#define MAX 51
using namespace std;
int N, M, ans;

class Trie {
private:
    Trie *next[alphabet];
    bool finished;

public:
    Trie() {
        fill(next, next + alphabet, nullptr);
        finished = false;
    }

    ~Trie() {
        for (int i = 0; i < alphabet; i++) {
            if (next[i])
                delete next[i];
        }
    }

    void insert(char *key) { // char 배열을 받음.
        if (*key == '\0') {
            finished = true;
            return;
        }
        int nextIdx = *key - 'a'; // char -> int
        if (!next[nextIdx]) //
            next[nextIdx] = new Trie();
        next[nextIdx]->insert(key + 1);
    }

    bool find(char* key){
        if(*key == '\0'){
            if(!this->finished)
                return false;
            return true;
        }

        int nextIdx = *key - 'a';
        if(next[nextIdx] == nullptr)
            return false;
        return next[nextIdx]->find(key+1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    Trie *root = new Trie();
    for (int i = 0; i < N; i++) {
        char str[MAX];
        cin >> str;
        root->insert(str);
    }

    for (int i = 0; i < M; i++) {
        char str[MAX];
        cin >> str;
        if (root->find(str)) {
            ans++;
        }
    }
    cout << ans << '\n';

}
