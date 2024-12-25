#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<char>> labirinto;
vector<vector<bool>> visitados;
stack<pair<int, int>> novasParedes;

int X[] = {1, 0, 0, -1};
int Y[] = {0, -1, 1, 0};

void dfs(int x, int y) {
    visitados[x][y] = true;
    novasParedes.push({x, y});

    for (int i = 0; i < 4; i++)
        if (labirinto[x + X[i]][y + Y[i]] == '.' && !visitados[x + X[i]][y + Y[i]])
            dfs(x + X[i], y + Y[i]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    labirinto.resize(n+2);
    visitados.resize(n+2);
    
    for (int i = 0; i < n+2; i++) {
        labirinto[i].resize(m+2, '#');
        visitados[i].resize(m+2, false);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> labirinto[i][j];
    
    int it = 0;
    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            if (labirinto[i][j] == '.') {
                dfs(i, j);
                it++;
                break;
            }
        }
        if (it > 0)
            break;
    }
    int count = 0;
    while (count < k) {
        int x, y;
        tie(x, y) = novasParedes.top();
        novasParedes.pop();
        labirinto[x][y] = 'X';
        count++;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cout << labirinto[i][j];
        cout << endl;
    }

    return 0;
}
