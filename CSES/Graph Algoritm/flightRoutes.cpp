#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> par;
int k;

vector<priority_queue<int, vector<int>, greater<int>>> dijkstra(vector<vector<par>> & grafo, int s) {
    vector<priority_queue<int, vector<int>, greater<int>>> D(grafo.size());
    priority_queue<par, vector<par>, greater<par>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int c, v;
        tie(c, v) = pq.top();
        pq.pop();
        if (D[v].size() >= k) continue;
        D[v].push(c);
        for (par & adj : grafo[v]) {
            int u, p;
            tie(u, p) = adj;
            if (D[u].size() < k) {
                pq.push({c + p, u});
            }
        }
    }
    return D;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m >> k;
    vector<vector<par>> grafo(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
    }
    vector<priority_queue<int, vector<int>, greater<int>>> caminhos = dijkstra(grafo, 1);
    
    while (!caminhos[n].empty()) {
        cout << caminhos[n].top() << " ";
        caminhos[n].pop();
    }
    cout << endl;

    return 0;
}