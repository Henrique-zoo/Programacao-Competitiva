#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> matriz(n+1, vector<int>(m+1));
    vector<vector<int>> matriz2(n+1, vector<int>(m+1));
    vector<int> trocaLinhas(n+1);
    vector<int> trocaColunas(m+1);

    for (int i = 0; i <= n; i++)
        trocaLinhas[i] = i;
    for (int i = 0; i <= m; i++)
        trocaColunas[i] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            matriz[i][j] = j + (i-1)*m;
    char op;
    int a, b;
    while (p--) {
        cin >> op >> a >> b;
        if (op == 'L') {
            int temp = trocaLinhas[b];
            trocaLinhas[b] = trocaLinhas[a];
            trocaLinhas[a] = temp;
        } else {
            int temp = trocaColunas[b];
            trocaColunas[b] = trocaColunas[a];
            trocaColunas[a] = temp;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int j = trocaColunas[i];
        for (int k = 1; k <= n; k++)
            matriz2[k][i] = matriz[k][j];
    }
    matriz = matriz2;
    for (int i = 1; i <= n; i++) {
        int j = trocaLinhas[i];
        matriz2[i] = matriz[j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << matriz2[i][j] << " ";
        cout << endl;
    }

    return 0;
}