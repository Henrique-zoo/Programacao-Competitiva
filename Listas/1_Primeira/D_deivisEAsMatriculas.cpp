#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    vector<string> nomes; vector<string> nomesOrdenados;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string nome;
        cin >> nome;
        nomes.push_back(nome);
    }
    nomesOrdenados = nomes;
    sort(nomesOrdenados.begin(), nomesOrdenados.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nomes[i] == nomesOrdenados[j]) {
                cout << j << " ";
                break;
            }
        }
    }
}