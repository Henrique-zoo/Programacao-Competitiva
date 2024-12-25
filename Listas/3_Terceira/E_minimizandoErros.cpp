#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k1, k2, aux;
    cin >> n >> k1 >> k2;
    vector<int> a(n);
    priority_queue<int> diferencas;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> aux;
        diferencas.push(abs(a[i] - aux));
    }

    for (int i = 0; i < k1+k2; i++) {
        int maiorDif = diferencas.top();
        diferencas.pop();
        diferencas.push(abs(maiorDif-1));
    }

    long long erro = 0;
    while (!diferencas.empty()) {
        int dif = diferencas.top();
        diferencas.pop();
        erro += 1LL * dif * dif;
    }
    cout << erro << endl;
    return 0;
}