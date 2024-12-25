#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<bool> visitados(n+1, false);
    vector<vector<int>> adj(n+1);
    vector<int> caminhos(n+1, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> fila;
    int atual;
    fila.push(1);
    visitados[1] = true;

    while (!fila.empty()) {
        atual = fila.front();
        fila.pop();
        if (atual == n)
            break;

        for (int vizinho : adj[atual]) {
            if (!visitados[vizinho]) {
                fila.push(vizinho);
                caminhos[vizinho] = atual;
                visitados[vizinho] = true;
            }
        }
    }
    vector<int> caminho;
    if (atual == n) {

        while (atual != 0) {
            caminho.push_back(atual);
            atual = caminhos[atual];
        }
        reverse(caminho.begin(), caminho.end());
        cout << caminho.size() << endl;
        int t = caminho.size();
        for (int i = 0; i < t; i++)
            cout << caminho[i] << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}