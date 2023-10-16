#include <iostream>
#include <map>

using namespace std;

map<string, string> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    string site, pw;
    while (N--) {
        cin >> site >> pw;
        m.insert({site, pw});
    }
    while (M--) {
        cin >> site;
        cout << m.find(site)->second << '\n';
    }

}