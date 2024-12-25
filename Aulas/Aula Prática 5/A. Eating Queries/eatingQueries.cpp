#include <bits/stdc++.h>
using namespace std;

int lower_bound(int x, int n, vector<int>& v) {
    int l = 0, r = n, k, ans = -1;
    while (l <= r) {
        k = (l+r)/2;
        if (v[k] >= x) {
            ans = k;
            r = k - 1;
        } else {
            l = k + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> t;
    while (t--) {
        int n, q, chave;
        cin >> n >> q;
        vector<int> somas(n+1, 0);
        vector<int> doces(n);
        for (int i = 0; i < n; i++)
            cin >> doces[i];
        sort(doces.begin(), doces.end(), greater<int>());
        for (int i = 1; i <= n; i++)
            somas[i] = somas[i-1] + doces[i-1];
        for (int i = 0; i < q; i++) {
            cin >> chave;
            cout << lower_bound(chave, n, somas) << endl;
        }
    }
}