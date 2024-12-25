#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s, r, k;
    int n;
    map<char, char> dicio;
    cin >> s >> r >> n;
    for (int i = 0; i < s.length(); i++) {
        int d = ('a' - 'A');
        dicio[s[i]] = r[i];
        dicio[s[i] - d] = r[i] - d;
    }
    while (n--) {
        cin >> k;
        for (int i = 0; i < k.length(); i++) {
            if ('0' <= k[i] && k[i] <= '9')
                cout << k[i];
            else
                cout << dicio[k[i]];
        }
        cout << "\n";
    }
}