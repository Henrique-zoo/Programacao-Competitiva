#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> trio;
typedef pair<int, int> par;

struct menor {
    bool operator() (trio a, trio b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) > get<0>(b);
    }
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<char>> mapa(n + 2, vector<char>(m+2, 'M'));
	vector<vector<bool>> visitados(n+2, vector<bool>(m+2, false));

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> mapa[i][j];
            
    int lagos = 0;
    priority_queue<trio, vector<trio>, menor> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(mapa[i][j] == '.' && !visitados[i][j]) {
                stack<par> pilha;
                pilha.push({i, j});
                int tamanho = 0;
                bool matar = false;
                while(!pilha.empty()) {
                    tamanho++;
                    int x, y;
                    tie(x, y) = pilha.top();
                    pilha.pop();
                    visitados[x][y] = true;
                    
                    if(mapa[x-1][y] == '.' && !visitados[x-1][y]) {
                        pilha.push({x-1, y});
                        visitados[x-1][y] = true;
                    } else if (mapa[x-1][y] == 'M') {
                        matar = true;
                    }
                    if(mapa[x][y-1] == '.' && !visitados[x][y-1]) {
                        pilha.push({x, y-1});
                        visitados[x][y-1] = true;
                    } else if (mapa[x][y-1] == 'M') {
                        matar = true;
                    }
                    if(mapa[x+1][y] == '.' && !visitados[x+1][y]) {
                        pilha.push({x+1, y});
                        visitados[x+1][y] = true;
                    } else if (mapa[x+1][y] == 'M') {
                        matar = true;
                    }
                    if(mapa[x][y+1] == '.' && !visitados[x][y+1]) {
                        pilha.push({x, y+1});
                        visitados[x][y+1] = true;
                    } else if (mapa[x][y+1] == 'M') {
                        matar = true;
                    }
                }
                if (!matar) {
                    pq.push(make_tuple(tamanho, i, j));
                    lagos++;
                }
            }
        }
    }
    int soma = 0;
    int count = 0;
    vector<vector<bool>> visitados2(n+2, vector<bool>(m+2, false));
	while (lagos-count > k) {
        int t, i, j;
        tie(t, i, j) = pq.top();
        pq.pop();
        soma += t;
        queue<par> fila;
        fila.push({i,j});
        while(!fila.empty()) {
            int x, y;
            tie(x, y) = fila.front();
            fila.pop();
            mapa[x][y] = '*';
            if(mapa[x-1][y] == '.' && !visitados2[x-1][y]) {
                fila.push({x-1, y});
                visitados2[x-1][y] = true;
            }
            if(mapa[x][y-1] == '.' && !visitados2[x][y-1]) {
                fila.push({x, y-1});
                visitados2[x][y-1] = true;
            }
            if(mapa[x+1][y] == '.' && !visitados2[x+1][y]) {
                fila.push({x+1, y});
                visitados2[x+1][y] = true;
            }
            if(mapa[x][y+1] == '.' && !visitados2[x][y+1]) {
                fila.push({x, y+1});
                visitados2[x][y+1] = true;
            }
        }
        count++;
    }
    cout << soma << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mapa[i][j];
        cout << endl;
    }
	return 0;
}