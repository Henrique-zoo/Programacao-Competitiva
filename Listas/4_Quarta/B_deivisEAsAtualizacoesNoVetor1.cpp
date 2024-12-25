#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> delta (n+2, 0), psum(n+1, 0);
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        delta[l] += x;
        delta[r+1] -= x; 
    }
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + delta[i];
        cout << psum[i] << " ";
    }
    cout << endl;
}