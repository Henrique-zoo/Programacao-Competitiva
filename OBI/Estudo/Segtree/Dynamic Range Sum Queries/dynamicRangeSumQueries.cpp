#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];

    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    int x[n+1];
    x[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    build(x, 1, 0, n);
    int op, a, b;
    while (q--) {
        cin >> op >> a >> b;
        if (op == 1)
            update(1, 0, n, a, b);
        else {
            int ans = sum(1, 0, n, a, b);
            cout << ans << endl;
        }
    }

    return 0;
}