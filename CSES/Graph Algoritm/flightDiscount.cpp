#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> par;
 
vector<ll> dijkstra(vector<vector<par>> & grafo, int s) {
    vector<ll> D(grafo.size(), 1e18);
    vector<bool> visitado(grafo.size(), false);
    priority_queue<par, vector<par>, greater<par>> fila;
    D[s] = 0;
    fila.push({D[s], s});
 
    while (!fila.empty()) {
        ll c, v;
        tie(c, v) = fila.top();
        fila.pop();
        if (!visitado[v]) {
            visitado[v] = true;
            for (par & adj : grafo[v]) {
                ll u, p;
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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m, a, b, c;
    cin >> n >> m;
    vector<vector<par>> grafo(2*(n));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        grafo[a-1].push_back({b-1, c});
        grafo[a-1 + n].push_back({b-1 + n, c});
        grafo[a-1].push_back({b-1 + n, c/2});
    }
    vector<ll> precos = dijkstra(grafo, 0);
    cout << precos[n + n - 1] << endl;
}