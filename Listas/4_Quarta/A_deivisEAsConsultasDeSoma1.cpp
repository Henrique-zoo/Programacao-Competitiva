#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int n, q, aux, l, r;
    cin >> n >> q;
    vector<long long int> psum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        psum[i] = psum[i-1] + aux;
    }
    while (q--) {
        cin >> l >> r;
        cout << psum[r] - psum[l-1] << endl;
    }

    return 0;
}