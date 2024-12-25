#include <bits/stdc++.h>
using namespace std;

int fibonnaci(int a, vector<int> lista) {
    int t = lista.size()-1;
    if (t <= a) {
        lista.push_back(lista[t]+lista[t-1]);
        return fibonnaci(a, lista);
    }
    return lista[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, termo;
    vector<int> lista;
    lista.push_back(0);
    lista.push_back(0);
    lista.push_back(1);
    cin >> n;
    termo = fibonnaci(n, lista);
    cout << termo << endl;
}