#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        
        int l = 0, r = 0;
        long long soma = 0;
        while (r < n) {
            if (v[r] >= v[l] && ((v[r]> 0 && v[l] > 0) || (v[r] < 0 && v[l] < 0)))
                l = r;
            if ((v[l] < 0 && v[r] > 0) || (v[l] > 0 && v[r] < 0)) {
                soma += v[l];
                l = r;
            }
            r++;
        }
        soma += v[l];
        cout << soma << endl;
    }
    return 0;
}