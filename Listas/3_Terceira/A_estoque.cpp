#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, op, produto;
    unordered_set<int> p;
    cin >> n;
    while (n--) {
        cin >> op >> produto;
        if (op == 1) {
            p.insert(produto);
        } else {
            if (p.count(produto)) {
                cout << "Sim\n";
            } else {
                cout << "Nao\n";
            }
        }
    }
    return 0;
}