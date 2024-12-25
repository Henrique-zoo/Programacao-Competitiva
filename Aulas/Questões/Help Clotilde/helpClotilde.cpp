#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void botaNaFila(int destino, int novo, unordered_set<int>& proibidos, queue<pii>& fila, int i) {
    if (novo == destino) {
        cout << i+1 << endl;
        return;
    }
    if (!proibidos.count(novo)) {
        fila.push({novo, i+1});
        proibidos.insert(novo);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true) {
        int cInicial, cDestino, nProibidos, aux;
        unordered_set<int> cProibidos;
        queue<pii> fila;
        bool invalido = false;
        cin >> cInicial >> cDestino >> nProibidos;

        if ((cInicial == cDestino) && (cInicial == nProibidos) && (cInicial == 0)) {
            break;
        }
        if (cInicial == nProibidos || cDestino == nProibidos) {
            invalido = true;
        }
        while (nProibidos--) {
            cin >> aux;
            cProibidos.insert(aux);
        }
        fila.push({cInicial, 0});
        int novoCanal, canal, i;
        if (invalido)
            cout << -1 << endl;
        else {
            while (true) {
                tie(canal, i) = fila.front();
                fila.pop();
                if (canal % 2 == 0) {
                    novoCanal = canal/2;
                    botaNaFila(cDestino, novoCanal, &cProibidos, &fila, i);
                }
                novoCanal = canal+1;
                botaNaFila(cDestino, novoCanal, &cProibidos, &fila, i);
                novoCanal = canal-1;
                botaNaFila(cDestino, novoCanal, &cProibidos, &fila, i);
                novoCanal = canal*2;
                botaNaFila(cDestino, novoCanal, &cProibidos, &fila, i);
                novoCanal = canal*3;
                botaNaFila(cDestino, novoCanal, &cProibidos, &fila, i);
            }
        }
    }
}