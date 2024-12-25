#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> canais(k);

    int canalAtual = 0;
    bool praDireita = true;

    int celulas_adicionadas = 0;

    for(int i = 1; i <= n; ++i){
        if(praDireita)
            for(int j = 1; j <= m; ++j){
                canais[canalAtual].push_back({i, j});
                celulas_adicionadas++;
                
                if(canalAtual < k - 1 && canais[canalAtual].size() == 2)
                    canalAtual++;
            }
        else
            for(int j = m; j >= 1; --j){
                canais[canalAtual].push_back({i, j});
                celulas_adicionadas++;
                
                if(canalAtual < k - 1 && canais[canalAtual].size() == 2)
                    canalAtual++;
            }
        praDireita = !praDireita;
    }

    for(int i = 0; i < k; ++i){
        cout << canais[i].size() << " ";
        for(auto & celula : canais[i])
            cout << celula.first << " " << celula.second << " ";
        cout << endl;
    }

    return 0;
}