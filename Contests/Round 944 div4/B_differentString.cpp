#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int count = 0;
        string s;
        string r = "";
        cin >> s;
        int tamanho = s.length();
        r += s[tamanho-1];
        for (int i = 1; i < tamanho; i++) {
            if (s[i] != s[0]) {
                count++;
            }
            r += s[i-1];
        }
        if (count == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << r << "\n";
        }
    }
    return 0;
}