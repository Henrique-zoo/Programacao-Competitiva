#include <bits/stdc++.h>
#define int long long
using namespace std;

int representante(int a, vector<int>& v) {
    if (v[a] == a)
        return a;
    return v[a] = representante(v[a], v);
}

bool consulta(int a, int b, vector<int>& v) {
    return representante(a, v) == representante(b, v);
}

void fusao(int a, int b, vector<int>& v) {
    a = representante(a, v);
    b = representante(b, v);
    v[b] = a;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> dsu(n+1);

    for (int i = 1; i <= n; i++)
        dsu[i] = i;

    vector<vector<int>> arestas(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arestas[i] = {c, a, b};
    }

    sort(arestas.begin(), arestas.end());
    int custo = 0;

    for (int i = 0; i < m; i++) {
        int c = arestas[i][0];
        int a = arestas[i][1];
        int b = arestas[i][2];

        if (consulta(a, b, dsu))
            continue;
        fusao(a, b, dsu);
        custo += c;
    }
    int count = -1;
    for (int i = 1; i <= n; i++) {
        if (dsu[i] == i)
            count++;
    }

    if (!count)
        cout << custo << endl;
    else
        cout << "IMPOSSIBLE\n";
}