#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (a^a) + (b^a) << endl;
    }
}