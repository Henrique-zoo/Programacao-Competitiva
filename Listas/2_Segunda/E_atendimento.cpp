#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tii;

struct menor {
    bool operator() (tii a, tii b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        else
            return get<0>(a) > get<0>(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    int m, n, v, q, indice;
    priority_queue<tii, vector<tii>, menor> funcionarios;
    int tempo = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v;
        funcionarios.push({tempo, i, v});
    }
    int maior = 0;
    for (int i = 0; i < m; i++) {
        cin >> q;
        tie(tempo, indice, v) = funcionarios.top();
        funcionarios.pop();
        tempo += v*q;
        funcionarios.push({tempo, indice, v});
        if (tempo > maior) {
            maior = tempo;
        }
    }
    cout << maior << endl;
}
