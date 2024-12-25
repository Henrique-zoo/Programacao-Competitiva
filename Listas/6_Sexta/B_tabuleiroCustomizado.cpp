#include<bits/stdc++.h>

using namespace std;
typedef pair<pair<int, int>, int> par;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> tabuleiro(n+2, vector<char>(m + 2, '-'));
	vector<vector<bool>> visitados(n+2, vector<bool>(m + 2, false));

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> tabuleiro[i][j];

	int letra = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(tabuleiro[i][j] == '.' && !visitados[i][j]) {
                queue<par> fila;
                fila.push({{i, j}, letra});
                while(!fila.empty()) {
                    pair<int, int> posicao;
                    int x, y;
                    tie(posicao, letra) = fila.front();
                    fila.pop();
                    tie(x,y) = posicao;
                    visitados[x][y] = true;

                    if(letra % 2 == 0)
                        tabuleiro[x][y] = 'B';
                    else
                        tabuleiro[x][y] = 'W';
                    
                    if(tabuleiro[x-1][y] == '.' && !visitados[x-1][y]) {
                        fila.push({{x-1, y}, letra+1});
                        visitados[x-1][y] = true;
                    }
                    if(tabuleiro[x][y-1] == '.' && !visitados[x][y-1]) {
                        fila.push({{x, y-1}, letra+1});
                        visitados[x][y-1] = true;
                    }
                    if(tabuleiro[x+1][y] == '.' && !visitados[x+1][y]) {
                        fila.push({{x+1, y}, letra+1});
                        visitados[x+1][y] = true;
                    }
                    if(tabuleiro[x][y+1] == '.' && !visitados[x][y+1]) {
                        fila.push({{x, y+1}, letra + 1});
                        visitados[x][y+1] = true;
                    }
                }
            }
        }
    }

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cout << tabuleiro[i][j];
		cout << endl;
	}
	return 0;
}