#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;

vector<int> dijkstra(vector<vector<par>> & grafo, int s) {
    vector<int> D(grafo.size(), 1e9+7);
    vector<bool> visitado(grafo.size(), false);
    priority_queue<par, vector<par>, greater<par>> fila;
    D[s] = 0;
    fila.push({D[s], s});

    while (!fila.empty()) {
        int c, v;
        tie(c, v) = fila.top();
        fila.pop();
        if (!visitado[v]) {
            visitado[v] = true;
            for (par & adj : grafo[v]) {
                int u, p;
                tie(u, p) = adj;
                if (p + c < D[u]) {
                    D[u] = p + c;
                    fila.push({D[u], u});
                }
            }
        }
    }

    return D;
}

int main() {
    int n, m, u, v, p, s;
    cin >> n >> m;
    vector<vector<par>> grafo(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        grafo[u-1].push_back({v-1, p});
        grafo[v-1].push_back({u-1, p});
    }
    cin >> s;
    vector<int> caminhos = dijkstra(grafo, s-1);

    auto maior = max_element(caminhos.begin(), caminhos.end());
    caminhos[s-1] = *maior;
    auto menor = min_element(caminhos.begin(), caminhos.end());

    cout << *maior - *menor << endl;
}