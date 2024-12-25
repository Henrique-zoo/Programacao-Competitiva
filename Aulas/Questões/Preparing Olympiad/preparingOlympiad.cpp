#include <bits/stdc++.h>
using namespace std;
int n, l, r, x;
vector<int> v;

int dfs(int i, int mais_facil, int mais_dificil, int total, int qtd) {
    if (i == n) {
        if (qtd >= 2 && total >= l && total <= r && (mais_dificil-mais_facil >= x))
            return 1;
        return 0;
    }
    return dfs(i+1, min(mais_facil, v[i]), max(mais_dificil, v[i]), total+v[i], qtd+1) + dfs(i+1, mais_facil, mais_dificil, total, qtd);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int aux;
    cin >> n >> l >> r >> x;
    for (int j = 0; j < n; j++) {
        cin >> aux;
        v.push_back(aux);
    }
    cout << dfs(0, 1000001, 0, 0, 0) << endl;
}