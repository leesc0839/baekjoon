//
// Created by 이승철 on 2022/07/24.
//
#include <iostream>
#include <queue>

using namespace std;
int peopleCnt, height, cnt;
int returnValue;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> peopleCnt >> height >> cnt;
    priority_queue<int> pq;
    for (int i = 0; i < peopleCnt; i++) {
        int h;
        cin >> h;
        pq.push(h);
    }
    while (cnt--) {
        if (pq.top() < height)
            break;
        returnValue++;
        int maxHeight = pq.top();
        pq.pop();
        if (maxHeight == 1)
            pq.push(1);
        else
            pq.push(maxHeight / 2);
    }
    if (pq.top() >= height) {
        cout << "NO" << '\n' << pq.top();
    } else {
        cout<<"YES"<<'\n'<<returnValue;
    }

}

