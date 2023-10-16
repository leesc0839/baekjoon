//
// Created by 이승철 on 2023/03/09.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Node {
public:
    string elem;
    map<string, Node *> child;

    Node(string e) {
        elem = e;
    }
};

int N, K;
string food;
Node *root;


void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> K; // depth

        // parent
        Node *pNode = root;

        // child
        for (int j = 0; j < K; j++) {
            cin >> food;
            Node *cNode;
            if (pNode->child.count(food))
                pNode = pNode->child.find(food)->second;
            else {
                cNode = new Node(food);
                pNode->child.insert({food, cNode});
                pNode = cNode;
            }
        }
    }
}

void fun(Node *node, int depth) {
    if (node->child.empty())
        return;

    for (auto nxt: node->child) {
        for (int i = 0; i < depth; i++)
            cout << "--";
        cout << nxt.first << '\n';
        fun(nxt.second, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    root = new Node("");
    input();
    fun(root, 0);
}
