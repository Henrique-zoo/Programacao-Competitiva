#include <bits/stdc++.h>
using namespace std;

int soma(int a, int sum) {
    if (a > 0) {
        sum += a;
        return soma(a-1, sum);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, sum;
    cin >> n;
    sum = 0;
    sum = soma(n, sum);
    cout << sum << endl;
}