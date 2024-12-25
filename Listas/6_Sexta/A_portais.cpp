#include <bits/stdc++.h>
using namespace std;

vector<int> portais;
int n, t;

bool dfs(int atual) {
    if (atual == t)
        return true;
    if (atual >= n)
        return false;
    return dfs(atual + portais[atual]);
}

int main() {
    cin >> n >> t;
    portais.resize(n);
    
    for (int i = 1; i < n; ++i)
        cin >> portais[i];
    if (dfs(1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
