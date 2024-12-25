#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n, m, c, aux;
    cin >> n >> m >> c;

    vector<ll> msg(n,0), delta(n+2,0), psum(n+1,0), resposta;
    for (int i = 0; i < n; i++) {
        cin >> msg[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> aux;
        delta[i] += aux;
        delta[i+n-m+1] -= aux;
    }
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i-1] + delta[i];
    for (int i = 0; i < n; i++)
        cout << (msg[i]+psum[i+1])%c << " ";
    cout << endl;

    return 0;
}