#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main() {
    int t, n, l, r, tempo;
    cin >> t;
    while (t--) {
        cin >> n;
        queue<pii> fila;

        for (int i = 0; i < n; i++) {
            cin >> l >> r;
            fila.push({l, r});
        }
        tempo = 1;
        while(!fila.empty()) {
            pii atual = fila.front();
            fila.pop();
            if (atual.first >= tempo) {
                tempo = atual.first;
                cout << tempo++ << " ";
            } else {
                if(atual.second >= tempo)
                    cout << tempo++ << " ";
                else
                    cout << "0 ";
            }
        }
        cout << "\n";
    }
}