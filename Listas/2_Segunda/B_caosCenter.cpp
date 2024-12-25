#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int,int,int> cincun;

struct menor {
    bool operator() (cincun a, cincun b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) > get<0>(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tempoAtendimento, espera, retorno, pos, entrada;
    priority_queue<cincun, vector<cincun>, menor> fila;
    cin >> n;
    int tempoAtual = 0;
    for (int i = 0; i < n; i++) {
        cin >> tempoAtendimento >> espera >> retorno;
        fila.push({tempoAtual,i,tempoAtendimento,espera,retorno});
    }
    while (!fila.empty()) {
        tie(entrada,pos,tempoAtendimento,espera,retorno) = fila.top();
        fila.pop();
        if (entrada > tempoAtual)
            tempoAtual = entrada;
        if (entrada+espera >= tempoAtual)
            tempoAtual += tempoAtendimento;
        else
            fila.push({entrada+espera+retorno,pos,tempoAtendimento,espera,retorno});
    }
    cout << tempoAtual << endl;
    return 0;
}