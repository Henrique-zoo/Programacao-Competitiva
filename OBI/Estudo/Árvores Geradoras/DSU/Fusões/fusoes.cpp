#include <bits/stdc++.h>
using namespace std;

int representante(int a, vector<int>& v) {
    if (v[a] == a)
        return a;
    return v[a] = representante(v[a], v);
}

bool consulta(int a, int b, vector<int>& v) {
    return representante(a, v) == representante(b, v);
}

void fusao(int a, int b, vector<int>& v) {
    a = representante(a, v);
    b = representante(b, v);
    v[b] = a;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> representante(n+1);
    for (int i = 1; i <= n; i++)
        representante[i] = i;

    for (int i = 0; i < k; i++) {
        char tipo;
        int x, y;
        cin >> tipo >> x >> y;
        
        if (tipo == 'F')
            fusao(x, y, representante);
        else if (consulta(x, y, representante))
            cout << "S\n";
        else
            cout << "N\n";
    }
}