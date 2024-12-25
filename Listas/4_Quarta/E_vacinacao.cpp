#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> delta(n+2,0), deltaOps(n+2,0), psum(n+2,0), psumOps(n+2,0), gripados(n,0);
    for (int i = 0; i < n; i++)
        cin >> gripados[i];
    while (m--) {
        ll l, r, a;
        cin >> l >> r >> a;
        delta[l] += a;
        deltaOps[l]++;
        delta[r+1] -= a;
        deltaOps[r+1]--;
    }
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + delta[i];
        psumOps[i] = psumOps[i-1] + deltaOps[i];
    }
    for (int i = 0; i < n; i++)
        gripados[i] -= psum[i+1];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (gripados[i] > 0)
            count += psumOps[i+1];
    }
    cout << count << endl;
}