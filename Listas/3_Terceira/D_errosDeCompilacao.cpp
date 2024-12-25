#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, aux, soma2;
    int soma = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        soma += aux;
    } n--;

    soma2 = soma;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        soma -= aux;
    } n--;

    soma2 -= soma;
    cout << soma << endl;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        soma2 -= aux;
    }
    cout << soma2 << endl;

    return 0;
}