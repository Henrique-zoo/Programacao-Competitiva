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
        string s;
        cin >> s;
        int l = 0, r = n-1;
        for (int i = 0; i < n; i++)
            v[i] = (int)s[i];

        int count = 0;
        while (l < r) {
            if (v[l++]^v[r--])
                count += 2;
            else
                break;
        }
        cout << n - count << endl;
    }
    return 0;
}