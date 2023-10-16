//
// Created by 이승철 on 2022/08/09.
//
#include <iostream>
#include <map>

using namespace std;
int t, elem, elem_sum, rtn_max;
map<int, pair<int, bool>> position[11]; // key : name , value : elem, visit
bool isUsed[11]; // position 별 채워짐 유무

void debug() {
    for (int i = 0; i < 11; i++) {
        for (auto c: position[i])
            cout << "position : " << i << " name : " << c.first << " elem : " << c.second.first << '\n';
        cout << '\n';
    }
}

void makeTeam(int cnt, int cur) {
    if (cnt == 11) {
        rtn_max = max(rtn_max, elem_sum);
        return;
    }
    for (int i = cur; i < 11; i++) {
        for (auto c: position[cnt]) {
            if (!c.second.second && !isUsed[c.first]) {
                isUsed[c.first] = true;
                c.second.second = true;
                elem_sum += c.second.first;

                makeTeam(cnt + 1, i + 1);

                isUsed[c.first] = false;
                c.second.second = false;
                elem_sum -= c.second.first;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        for (int r = 0; r < 11; r++) {
            for (int c = 0; c < 11; c++) {
                cin >> elem;
                if (elem != 0)
                    position[c].insert({r, {elem, false}});
            }
        }
        makeTeam(0, 0);
        cout << rtn_max << '\n';
        for (auto &i: position)
            i.clear();
        fill(isUsed, isUsed + 11, false);
        rtn_max = elem_sum = 0;
    }


}

