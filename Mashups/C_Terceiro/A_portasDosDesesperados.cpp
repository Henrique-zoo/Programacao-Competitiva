#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long int n, maior = -1001;
    int aux, creditosIniciais = 100;
    cin >> n;
    vector<long long int> psum(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        psum[i] = psum[i-1] + aux;
        if (psum[i] > maior) {
            maior = psum[i];
        }
    }
    if (maior < 0)
        maior = 0;
    cout << creditosIniciais + maior << endl;
}