#include <bits/stdc++.h>
using namespace std;

long long potencia(int a) {
    long long p = 1;
    for (int i = 0; i < a; i++)
        p *= 10;
    return p;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int r = n % 7;
        string s = to_string(n);
        long long k = potencia(s.length());
        int w = r*k + r;

        if (w % 7 == 0)
            cout << "Sim\n";
        else
            cout << "Nao\n";
    }

    return 0;
}