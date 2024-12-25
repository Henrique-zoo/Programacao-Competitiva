#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> grafo(n + 1);
    vector<bool> visitados(n + 1, false);
    vector<int> time(n + 1);
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    queue<int> fila;
    bool possivel = true;

    for (int i = 1; i <= n; i++) {
        if (!possivel)
            break;

        if (!visitados[i]) {
            fila.push(i);
            visitados[i] = true;
            time[i] = 0;

            while(!fila.empty()) {
                int atual = fila.front();
                fila.pop();
                int time_atual = time[atual];
                int prox_time = time_atual^1;

                for (int adj : grafo[atual]) {
                    if (!visitados[adj]) {
                        time[adj] = prox_time;
                        fila.push(adj);
                    } else if (time[adj] != prox_time) {
                        possivel = false;
                        break;
                    }
                    visitados[adj] = true;
                }
            }
        }
    }
    
    if (!possivel)
        cout << "IMPOSSIBLE\n";
    else
        for (int i = 1; i <= n; i++)
            cout << time[i] + 1 << " ";
    cout << endl;

    return 0;
}