#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, n, op, x, k;
    stack<int> pilha;
    cin >> p >> n;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {
            pilha.push(x);
            p += x;
        } else {
            for (int i = 0; i < x; i++) {
                k = pilha.top();
                pilha.pop();
                p -= k;
            }
        }
    }
    cout << p << endl;
}