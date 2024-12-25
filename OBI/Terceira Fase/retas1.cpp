#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<pii> v(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    int count = 0;
    for (int i = 0; i < n-1; i++) {
        if (((x1 * v[i].first + v[i].second) < (x1 * v[n-1].first + v[n-1].second)) && ((x2 * v[i].first + v[i].second) > x2 * v[n-1].first + v[n-1].second)) {
            count++;
        }
        if (((x1 * v[i].first + v[i].second) > (x1 * v[n-1].first + v[n-1].second)) && ((x2 * v[i].first + v[i].second) < x2 * v[n-1].first + v[n-1].second)) {
            count++;
        }
        if (((x1 * v[i].first + v[i].second) == (x1 * v[n-1].first + v[n-1].second)) || ((x2 * v[i].first + v[i].second) == x2 * v[n-1].first + v[n-1].second)) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}