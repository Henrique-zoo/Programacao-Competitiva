#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> int_pair;

int find(int a, vector<int>& v) {
    return v[a] == a ? a : v[a] = find(v[a], v);
}

bool consulta(int a, int b, vector<int>& v) {
    return find(a, v) == find(b, v);
}

void join(int a, int b, vector<int>& v) {
    a = find(a, v), b = find(b, v);
    if (a == b)
        return;
    v[b] = a;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> representantes(n+1);
    vector<int_pair> rotas(m);

    for (int i = 0; i <= n; i++)
        representantes[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        join(a, b, representantes);
    }

    queue<int_pair> fila;
    set<int> lideres;
    for (int i = 1; i <= n; i++)
        if (find(i, representantes) == i)
            lideres.insert(i);

    cout << lideres.size() - 1 << endl;
    for (auto elem : lideres) {
        if (elem != *lideres.begin())
            cout << *lideres.begin() << " " << elem << endl;
    }
}