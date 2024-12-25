#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, b, mask = 1;
    cin >> n;
    while (mask < n)
        mask = (mask << 1) | 1;
    b = mask ^ n;
    
    cout << n << " " << b << "\n";

    return 0;
}