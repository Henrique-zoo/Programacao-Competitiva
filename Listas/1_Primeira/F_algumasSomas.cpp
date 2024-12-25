#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int somaFinal = 0;
    for (int i = 1; i <= n; i++) {
        string k = to_string(i);
        int soma = 0;
        for (int j = 0; j < k.length(); j++) {
            soma += k[j] - '0';
        }
        if (a <= soma && soma <= b) {
            somaFinal += i;
        }
    }
    cout << somaFinal;
}