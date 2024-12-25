#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> visitados(n+2, vector<bool>(m+2, true));
    vector<vector<char>> direcao(n+2, vector<char>(m+2, 0));
    vector<vector<par>> anterior(n+2, vector<par>(m+2, {-1, -1}));
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    string passos = "RLDU";
    
    queue<par> fila;
    par destino, inicio;
    char aux;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> aux;
            if (aux != '#')
                visitados[i][j] = false;
            if (aux == 'A') {
                inicio = {i, j};
                fila.push(inicio);
                visitados[i][j] = true;
            }
            if (aux == 'B')
                destino = {i, j};
        }
    }

    int x, y;
    
    while (!fila.empty()) {
        par posicao = fila.front();
        fila.pop();
        tie(x, y) = posicao;

        if (x == destino.first && y == destino.second)
            break;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!visitados[nx][ny]) {
                fila.push({nx, ny});
                visitados[nx][ny] = true;
                direcao[nx][ny] = passos[i];
                anterior[nx][ny] = {x, y};
            }
        }
    }
    if (x == destino.first && y == destino.second) {
        string caminho;
        par atual = destino;
        while (atual != inicio) {
            caminho += direcao[atual.first][atual.second];
            atual = anterior[atual.first][atual.second];
        }
        reverse(caminho.begin(), caminho.end());
        cout << "YES\n" << caminho.length() << "\n" << caminho << endl;
    } else
        cout << "NO\n";

    return 0;
}