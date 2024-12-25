#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
vector<vector<int>> componente, tamanho;
vector<vector<char>> tabuleiro;

int bfs(int i, int j, int id) {
    queue<pii> fila;
    fila.push({i, j});
    componente[i][j] = id;
    int tam = 0;

    while (!fila.empty()) {
        int x, y;
        tie(x, y) = fila.front();
        fila.pop();
        tam++;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (tabuleiro[nx][ny] == '.' && componente[nx][ny] == 0) {
                fila.push({nx, ny});
                componente[nx][ny] = id;
            }
        }
    }

    return tam;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    tabuleiro = vector<vector<char>>(n + 2, vector<char>(m + 2, '*'));
    componente = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
    tamanho = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> tabuleiro[i][j];

    int id = 0;
    map<int, int> tamanhoComponente;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (tabuleiro[i][j] == '.' && componente[i][j] == 0) {
                id++;
                int tam = bfs(i, j, id);
                tamanhoComponente[id] = tam;
            }
        }
    }

    vector<string> saida(n, string(m, '.'));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (tabuleiro[i][j] == '*') {
                set<int> componentesVizinhos;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (tabuleiro[ni][nj] == '.' && componente[ni][nj] != 0) {
                        componentesVizinhos.insert(componente[ni][nj]);
                    }
                }
                int tam = 1;
                for (int comp : componentesVizinhos) {
                    tam += tamanhoComponente[comp];
                }
                saida[i-1][j-1] = (tam % 10) + '0';
            } else {
                saida[i-1][j-1] = '.';
            }
        }
    }

    for (const string& linha : saida)
        cout << linha << '\n';

    return 0;
}
