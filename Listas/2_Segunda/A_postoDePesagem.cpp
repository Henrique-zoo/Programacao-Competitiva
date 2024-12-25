#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, f, p;
    cin >> n >> f >> p;
    queue<int> fila;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fila.push(a);
    }
    int i = 0;
    int count = 0;
    while (!fila.empty()) {
        int elemRemovido = fila.front();
        if (i % f == 0) {
            if (elemRemovido > p) {
                count += 10;
                fila.push(elemRemovido - 2);
            } else {
                count += 5;
            }
        } else {
            count += 1;
        }
        fila.pop();
        i++;
    }
    cout << count << "\n";
}