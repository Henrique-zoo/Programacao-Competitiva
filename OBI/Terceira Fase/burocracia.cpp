#include <bits/stdc++.h>
using namespace std;

int representante(int a, int i, vector<int>& v) {
    if (i <= 0)
        return a;
    return representante(v[a], i-1, v);
}

bool consulta(int a, int b, vector<int>& v) {
    if (a == b)
        return true;
    if (v[a] == a)
        return false;
    return consulta(v[a], b, v);
}

void join(int a, vector<int>& v) {
    for (int i = a+1; i < v.size(); i++)
        if (consulta(i, a, v))
            v[i] = a;
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n;
    vector<int> dsu(n+1);
    dsu[1] = 1;

    for (int i = 2; i <= n; i++)
        cin >> dsu[i];
    cin >> q;

    while(q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int v, k;
            cin >> v >> k;
            cout << representante(v, k, dsu) << endl;
        } else {
            int v;
            cin >> v;
            join(v, dsu);
        }
    }

    return 0;
}