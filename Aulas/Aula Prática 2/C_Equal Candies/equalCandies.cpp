#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long int menor = 999999999;
        int c;
        cin >> c;
        int ans = 0;
        int sum = 0;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            sum += a;
            if (a < menor) {
                menor = a;
            }
        }
        ans = sum - (c * menor);
        cout << ans << "\n";
    }
}