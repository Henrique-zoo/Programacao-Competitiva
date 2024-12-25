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
    int k, n = 12;
    cin >> k;
    vector<int> somas(n+1, 0);
    vector<int> meses(n);
    for (int i = 0; i < n; i++)
        cin >> meses[i];

    sort(meses.begin(), meses.end(), greater<int>());
    for (int i = 1; i <= n; i++)
        somas[i] = somas[i-1] + meses[i-1];
    
    cout << lower_bound(k, n, somas) << endl;
}