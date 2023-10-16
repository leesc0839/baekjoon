#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define MX 51
#define HOUSE 1
#define CHICKEN 2

using namespace std;

struct Info {
    int r;
    int c;
};

int N, M, CHICKEN_COUNT;
int map[MX][MX], visit[MX][MX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<int> brute;
vector<Info> house;
vector<Info> chicken;
bool live[MX][MX];

bool OOB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N)
        return true;

    return false;
}

void init() {
    for (int i = 0; i < CHICKEN_COUNT - M; i++)
        brute.emplace_back(0);

    for (int i = 0; i < M; i++)
        brute.emplace_back(1);
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == HOUSE)
                house.push_back({i, j});

            if (map[i][j] == CHICKEN) {
                chicken.push_back({i, j});
                CHICKEN_COUNT++;
            }
        }
    }
}

int min_dist(int r, int c) {
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < CHICKEN_COUNT; i++) {
        if (brute[i] == 0)
            continue;
        int tmp = abs(chicken[i].r - r) + abs(chicken[i].c - c);
        ret = min(ret, tmp);
    }
    return ret;
}

int sol() {
    int answer = 0x3f3f3f3f;
    do {
        memset(live, 0, sizeof(live));
        for (int i = 0; i < brute.size(); i++) {
            if (brute[i] == 1)
                live[chicken[i].r][chicken[i].c] = true;
        }

        int ret = 0;
        for (auto cur: house)
            ret += min_dist(cur.r, cur.c);

        answer = min(answer, ret);
    } while (next_permutation(brute.begin(), brute.end()));

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    cout << sol();
}