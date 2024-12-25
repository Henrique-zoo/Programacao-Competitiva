#include <bits/stdc++.h>
using namespace std;
int main() {
    int e, m, d;
    cin >> e >> m >> d;
    pair<int, int> separados;
    pair<int, int> separadosI;
    set<pair<int, int>> s;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
    }
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        separados.first = x; separados.second = y;
        separadosI.first = y; separadosI.second = x;
        s.insert(separados);
        s.insert(separadosI);
    }
    int count = 0;
    for (int i = 0; i < e/3; i++) {
        int x, y, z;
        v.clear();
        cin >> x >> y >> z;
        pair p(x, y); pair p2(x, z); pair p3(y, z);
        v.push_back(p); v.push_back(p2); v.push_back(p3);
        for (int j = 0; j < v.size(); j++) {
            auto it = find(s.begin(), s.end(), v[j]);
            if (it != s.end()) {
                count++;
            }
        }
    }
    cout << count << "\n";
}