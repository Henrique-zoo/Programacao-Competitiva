#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> par;

vector<int> dijkstra(vector<vector<par>> & grafo, int s) {
    vector<int> D(grafo.size(), 1LL<<50);
    vector<bool> visitados(grafo.size(), false);
    priority_queue<par, vector<par>, greater<par>> pq;
    D[s] = 0;
    pq.push({D[s], s});

    while (!pq.empty()) {
        int c, v;
        tie(c, v) = pq.top();
        pq.pop();
        if (!visitados[v]) {
            visitados[v] = true;
            for (par & adj : grafo[v]) {
                int u, p;
                tie(u, p) = adj;
                if (c + p < D[u]) {
                    D[u] = c + p;
                    pq.push({D[u], u});
                }
            }
        }
    }
    return D;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<par>> grafo(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
    }
    vector<int> caminhos = dijkstra(grafo, 1);
    
    for (int i = 1; i <= n; i++)
        cout << caminhos[i] << " ";
    cout << endl;

    return 0;
}