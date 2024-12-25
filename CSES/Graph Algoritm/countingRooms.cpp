#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mapa(n+2, vector<char>(m+2, '#'));
    vector<vector<bool>> visitados(n+2, vector<bool>(m+2, false));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mapa[i][j];

    int quartos = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mapa[i][j] == '.' && !visitados[i][j]) {
                quartos++;
                queue<par> fila;
                fila.push({i, j});
                visitados[i][j] = true;
                while (!fila.empty()) {
                    int x, y;
                    tie(x, y) = fila.front();
                    fila.pop();

                    if (mapa[x][y+1] == '.' && !visitados[x][y+1]) {
                        fila.push({x, y+1});
                        visitados[x][y+1] = true;
                    }
                    if (mapa[x][y-1] == '.' && !visitados[x][y-1]) {
                        fila.push({x, y-1});
                        visitados[x][y-1] = true;
                    }
                    if (mapa[x-1][y] == '.' && !visitados[x-1][y]) {
                        fila.push({x-1, y});
                        visitados[x-1][y] = true;
                    }
                    if (mapa[x+1][y] == '.' && !visitados[x+1][y]) {
                        fila.push({x+1, y});
                        visitados[x+1][y] = true;
                    }
                }
            }
    cout << quartos << endl;

    return 0;
}