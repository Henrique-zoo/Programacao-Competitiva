#include <bits/stdc++.h>
using namespace std;

int main() {
    float n, nota, nf;
    cin >> n;
    float count = 0;
    for (int i = 0; i < n; i++) {
        char c, a;
        cin >> c >> a;
        if (c == a) {
            count += 1;
        }
    }
    nf = n;
    nota = count/nf *10;
    cout << fixed << setprecision(2) << "Nota: " << nota << "\n";
}