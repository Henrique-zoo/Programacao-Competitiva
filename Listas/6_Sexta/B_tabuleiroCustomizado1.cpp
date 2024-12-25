#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> matrizC;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    char aux;
    matrizC matriz;
    cin >> n >> m;
    matriz.resize(n, vector<char>(m,'-'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aux;
            if (aux != '-') {
                if ((i + j) % 2 == 0)
                    matriz[i][j] = 'B';
                else
                    matriz[i][j] = 'W';
            }
        }
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j];
        }
        cout << endl;
    }
}