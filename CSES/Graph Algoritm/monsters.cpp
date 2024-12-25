#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> par;


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    char aux;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    map<pair<int, int>, char> direcoes;
    direcoes[{1, 0}] = 'D';
    direcoes[{-1, 0}] = 'U';
    direcoes[{0, 1}] = 'R';
    direcoes[{0, -1}] = 'L';
    cin >> n >> m;
    vector<vector<int>> mapa(n+2, vector<int>(m+2, -2));
    vector<vector<tuple<int, int, char>>> caminhos(n+2, vector<tuple<int, int, char>>(m+2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> aux;
            if (aux == '#')
                mapa[i][j] = -1;
            else if (aux == '.')
                mapa[i][j] = 1e9;
            else if (aux == 'M')
                mapa[i][j] = 0;
            else
                mapa[i][j] = -3;
        }
    }

    queue<par> fila;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mapa[i][j] == 0)
                fila.push({i, j});
            
    while(!fila.empty()) {
        int x, y;
        tie(x, y) = fila.front();
        fila.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (mapa[nx][ny] > mapa[x][y] + 1) {
                mapa[nx][ny] = mapa[x][y] + 1;
                fila.push({nx, ny});
            }
        }
    }
    pair<int, int> begin;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mapa[i][j] == -3) {
                begin = {i, j};
                mapa[i][j] = 0;
                fila.push(begin);
            }
        }
    }


    pair<int, int> end = {0, 0};
    while(!fila.empty()) {
        if (end.f != 0)
            break;
        int x, y;
        tie(x, y) = fila.front();
        fila.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (mapa[nx][ny] > mapa[x][y] + 1) {
                mapa[nx][ny] = mapa[x][y] + 1;
                caminhos[nx][ny] = {x, y, direcoes[{dx[k], dy[k]}]};
                fila.push({nx, ny});
            } else if (mapa[nx][ny] == -2)
                end = {x, y};
        }
    }

    if (end.f != 0) {
        cout << "YES\n" << mapa[end.f][end.s] << endl;
        string s = "";
        pair<int, int> atual = end;
        while (atual != begin) {
            s += get<2>(caminhos[atual.f][atual.s]);
            atual = {get<0>(caminhos[atual.f][atual.s]), get<1>(caminhos[atual.f][atual.s])};
        }
        reverse(s.begin(), s.end());
        cout << s << endl;

    } else {
        cout << "NO\n";
    }

    return 0;
}