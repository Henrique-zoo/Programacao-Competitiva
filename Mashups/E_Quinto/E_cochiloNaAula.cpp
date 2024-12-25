#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    vector<long long> dormindo(n);
    vector<long long> soma(n + k, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> dormindo[i];
    for (int i = n-1; i >= n-k; i--) {
        soma[i] = soma[i+1] + v[i]*(dormindo[i]^1);
    }
    for (int i = n-k; i >= 0; i--) {
        soma[i] = soma[i+1] + (dormindo[i]^1)*v[i] - soma[i+k];
    }
    long long teoremas = 0;
    for (int i = 0; i < n; i++)
        if (dormindo[i])
            teoremas += v[i];
    auto it = max_element(soma.begin(), soma.end());
    teoremas += *it;
    cout << teoremas << endl;
}