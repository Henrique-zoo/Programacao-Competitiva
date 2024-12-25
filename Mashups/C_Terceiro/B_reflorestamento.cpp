#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long int n, m, q;
    cin >> n >> m >> q;
    vector<long long int> delta(n+2, 0), psum(n+2,0);
    vector<int> arvores(n);

    for (int i = 0; i < n; i++) {
        cin >> arvores[i];
    }
    while (q--) {
        long long int l, r, x, m;
        cin >> l >> r >> x >> m;
        if (m <= 5) {
            delta[l] += x;
            delta[r+1] -= x;
        }
    }
    for (int i = 1; i <= n+1; i++) {
        psum[i] = psum[i-1] + delta[i];
    }
    for (int i = 0; i < n; i++) {
        cout << psum[i+1] + arvores[i] << " ";
    }
    cout << endl;
}