#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, t, c, aux1, aux2;
    cin >> n >> t >> c;
    vector<int> temps(200001, 0);
    vector<int> delta(200002,0);
    vector<int> aceitavel(200001,0);
    for (int i = 0; i < n; i++) {
        cin >> aux1 >> aux2;
        delta[aux1]++;
        delta[aux2+1]--;
    }
    for (int i = 1; i <= 200001; i++) {
        temps[i] = temps[i-1] + delta[i];
    }
    for (int i = 1; i <= 200001; i++) {
        if (temps[i] >= t)
            aceitavel[i] = aceitavel[i-1] + 1;
        else
            aceitavel[i] = aceitavel[i-1];
    }
    for (int i = 92; i <= 102; i++) {
        cout << aceitavel[i] << " ";
    }
    for (int i = 0; i < c; i++) {
        cin >> aux1 >> aux2;
        cout << aceitavel[aux2]-aceitavel[aux1] << endl;
    }
}