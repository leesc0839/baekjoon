//
// Created by 이승철 on 2022/07/25.
//
#include <iostream>
#include <stack>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string cmd;
    cin >> cmd;
    stack<char> operator_stack;
    for (int i=0; i<cmd.length(); i++) {
        if (cmd[i] == '(')
            operator_stack.push(cmd[i]);
        else if (cmd[i] == '+' || cmd[i] == '-') {
            while (!operator_stack.empty() && operator_stack.top() != '(') { // 우선순위 자신보다 다 높거나 같으니 연산자 괄호 빼고 다 뺌
                cout << operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(cmd[i]);
        } else if (cmd[i] == '*' || cmd[i] == '/') {
            while (!operator_stack.empty() && (operator_stack.top() == '/' ||
                   operator_stack.top() == '*')) { // 우선순위 자신보다 다 높거나 같으니 연산자 괄호 빼고 다 뺌
                cout << operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(cmd[i]);
        } else if (cmd[i] == ')') {
            while (operator_stack.top() != '(') {
                cout << operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.pop(); // ( 뽑기
        } else // 피 연산자 바로 출력
            cout << cmd[i];
    }

    while (!operator_stack.empty()) {
        cout << operator_stack.top();
        operator_stack.pop();
    }

}
