#include <iostream>
#include <stack>

using namespace std;
int cnt;
stack<char> s;
string inputString;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> inputString;

    for (int i = 0; i < inputString.size(); i++) {
        if (inputString[i] == '(') { s.push(inputString[i]); }
        else if (inputString[i] == ')') {
            if (inputString[i-1] == '(') { // 레이저 일 때
                s.pop();
                cnt += (int) s.size();
            } else if (inputString[i-1] == ')') {
                cnt++;
                s.pop();
            }
        }
    }

    cout<<cnt;


}