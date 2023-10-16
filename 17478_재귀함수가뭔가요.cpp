//
// Created by 이승철 on 2022/11/16.
//
#include <iostream>

using namespace std;
int N;
string arr[7] = {"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n", "\"재귀함수가 뭔가요?\"\n",
                 "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",
                 "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n",
                 "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n",
                 "라고 답변하였지.\n"};
string bar = "____";

void make_bar(int cnt, int idx) {
    for (int i = 0; i < cnt; i++)
        cout << bar;
    cout << arr[idx];
}

void fun(int idx) {
    make_bar(idx, 1);
    if (idx == N)
        make_bar(idx, 5);
    else {
        for (int i = 2; i < 5; i++)
            make_bar(idx, i);
        fun(idx + 1);
    }
    make_bar(idx, 6);


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << arr[0];
    fun(0);

}
