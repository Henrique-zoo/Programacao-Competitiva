#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> plili;

plili compras(int n, int s, vector<int> v) {
    int l = 1, r = n;
    ll k, ans = 0;
    ll soma, melhorSoma = 0;
    while(l <= r) {
        k = (l+r)/2;
        vector<ll> custo;

        for (int i = 0; i < n; i++)
            custo.push_back(v[i]+(i+1)*k);
        sort(custo.begin(), custo.end());
        soma = 0;

        for (int i = 0; i < k; i++)
            soma += custo[i];
        if (soma <= s) {
            ans = k;
            melhorSoma = soma;
            l = k+1;
        } else {
            r = k-1;
        }
    }
    return {ans, melhorSoma};
}

int main() {
    int n, s;
    plili resposta;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    resposta = compras(n, s, v);
    cout << resposta.first << " " << resposta.second << endl;
}