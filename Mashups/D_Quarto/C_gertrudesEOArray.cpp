#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, aux;
        cin >> n;
        cin >> p;
        for (int i = 1; i < n; i++) {
            cin >> aux;
            p &= aux;
        }
        cout << p << endl;
    }
}