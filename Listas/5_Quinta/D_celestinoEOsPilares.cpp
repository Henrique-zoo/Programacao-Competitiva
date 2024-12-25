#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matriz(n, vector<int> (n));
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int menor = n;
            int indice;
            for (int j = 0; j < n; j++) {
                matriz[i][j] = i^j;
                if (matriz[i][j] < menor && i != j) {
                    menor = matriz[i][j];
                    indice = j;
                }
                v.push_back({menor, j});
            }
        }
        int m, i, z = 0;
        cout << n-1 << " ";
        while (z < n) {
            cout << v[i].second << " ";
            i = v[i].second;
            z++;
        }
        cout << i << endl;

    }
    
    return 0;
}