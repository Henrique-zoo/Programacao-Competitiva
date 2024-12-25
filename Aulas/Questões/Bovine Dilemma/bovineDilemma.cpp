#include <bits/stdc++.h>
using namespace std;

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, x;
    cin >> t;
    while (t--) {
        set<int> areas;
        vector<int> posicoes;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            posicoes.push_back(x);
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                areas.insert(posicoes[j]-posicoes[i]);
            }
        }
        cout << areas.size() << endl;
    }
    return 0;
}