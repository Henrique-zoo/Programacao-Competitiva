#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<int> primos(1000002, 1);
    vector<int> psum(1000003, 0);
    primos[0] = 0;
    primos[1] = 0;
    for (int i = 2; i < 1000002; i++)
        for (int j = 2; j*j <= i; j++)
            if (i % j == 0) {
                primos[i] = 0;
                break;
            }
    for (int i = 1; i < 1000002; i++) {
        psum[i] = psum[i-1] + primos[i];
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << psum[r] - psum[l] << endl;
    }

    return 0;
}