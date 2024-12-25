#include <bits/stdc++.h>
using namespace std;

int main() {
    float n, r, m, p;
    cin >> n >> r;
    cin >> m >> p;
    if ((r/n) > (p/m)) {
        cout << "Promocao";
    } else {
        cout << "Enganacao";
    }
}