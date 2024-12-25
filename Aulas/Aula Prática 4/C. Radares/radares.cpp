#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long int n, q, l;
    cin >> n >> q >> l;
    vector<long long int> delta(n+2, 0), psum(n+2,0);
    while (q--) {
        long long int li, r, m;
        cin >> li >> r >> m;
        if (m > l) {
            delta[li]++;
            delta[r+1]--;
        }
    }
    long long int maior = 0;
    for (int i = 1; i <= n+1; i++) {
        psum[i] = psum[i-1] + delta[i];
        if (psum[i] > maior)
            maior = psum[i];
    }
    long long int count = 0;
    long long int maiorQtd = 0;
    for (int i = 1; i <= n+1; i++) {
        if (psum[i] == maior) {
            count++;
        }
        if (count > 0 && psum[i] < maior) {
            if (count > maiorQtd)
                maiorQtd = count;
            count = 0;
        }
    }
    maiorQtd == 0 ? (cout << -1 << endl) : (cout << maiorQtd << endl);
}