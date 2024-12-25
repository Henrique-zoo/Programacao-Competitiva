#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, xc, yc, indice;
    long long int menor = 999999999999;
    cin >> n >> xc >> yc;
    for (int i = 1; i <= n; i++) {
        int xi, yi, p;
        cin >> xi >> yi >> p;
        int precoTotal = p + 2*(abs(xc-xi) + abs(yc-yi));
        if (precoTotal < menor) {
            menor = precoTotal;
            indice = i;
        }
    }
    cout << menor << " " << indice;
}