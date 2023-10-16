//
// Created by 이승철 on 2022/07/24.
//

#include <iostream>
#include <queue>
#include <list>

#define idx first
#define weight second

using namespace std;
int truckCnt, bridgeSize, bridgeWeight, sumWeightOnBridge, returnValue;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> truckCnt >> bridgeSize >> bridgeWeight;
    list<pair<int, int>> bridgeList;
    queue<int> truckQueue;

    for (int i = 0; i < truckCnt; i++) {
        int w;
        cin >> w;
        truckQueue.push(w);
    }

    while (true) {
        if (!bridgeList.empty()) {

            for(auto iter = bridgeList.begin(); iter!= bridgeList.end(); iter++) // 다리 위 트럭 앞으로 한칸
                iter->idx++;

            if (bridgeList.front().idx > bridgeSize) { // 빠지는 트럭 빼주기
                sumWeightOnBridge -= bridgeList.front().weight;
                bridgeList.pop_front();
            }
        }
        if (!truckQueue.empty() && bridgeList.size() < bridgeSize &&
            bridgeWeight >= sumWeightOnBridge + truckQueue.front()) { // 트럭 들어 오는 상황
            sumWeightOnBridge += truckQueue.front();
            bridgeList.emplace_back(1, truckQueue.front()); // 실제 트럭 추가
            truckQueue.pop();
        }

        returnValue++;
        if(truckQueue.empty() && bridgeList.empty())
            break;
    }

    cout << returnValue;

}