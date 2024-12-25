#include <bits/stdc++.h>
using namespace std;

int MAXN = 2e5;
int n, t[4*MAXN];

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tr];
    else {
        int tmid = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int segMin() {
    if (l > r) {
        return 0;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    return 0;
}