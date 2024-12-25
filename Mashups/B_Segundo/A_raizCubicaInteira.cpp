#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long int n;
    cin >> n;
    long long int i = 1;
    while (i*i*i < n) {
        i++;
    }
    if (i*i*i == n)
        cout << i;
    else
        cout << -1;
}