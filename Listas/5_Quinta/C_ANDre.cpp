#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, i = 1;
        cin >> n;
        
        while (i*2 <= n) {
            i *= 2;
        }
        cout << i-1 << endl;
    }
    
    return 0;
}