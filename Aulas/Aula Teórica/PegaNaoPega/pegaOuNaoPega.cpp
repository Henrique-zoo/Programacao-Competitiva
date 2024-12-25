#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
// Depth First Search
void dfs(int i, vector<int> estado) {
    if (i == n) {
        cout << '[';
        for (int j = 0; j < estado.size(); j++) {
            cout << estado[j];
            if (j != estado.size()-1)
                cout << ", ";
        }
        cout << ']' << endl;
        return;
    }
    dfs(i+1, estado); // Não pega
    estado.push_back(v[i]);
    dfs(i+1, estado); // Pega
}
int main() {
    int aux;
    vector<int> estado;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    dfs(0, estado);
}