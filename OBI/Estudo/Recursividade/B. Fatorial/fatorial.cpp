#include <bits/stdc++.h>
using namespace std;

long long int fatorial(int a, long long int prod) {
    if (a > 0) {
        prod *= a;
        return fatorial(a-1, prod);
    }
    return prod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long int produto = 1;
    cin >> n;
    produto = fatorial(n, produto);
    cout << produto << endl;
}