#include <bits/stdc++.h>
using namespace std;

string removeRepetidos(string a) {
    string substring = "";
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
        if ((a[i] != a[i+1] && a[i] != a[i-1]) || (count >= 2)) {
            substring += a[i];
        } else {
            count++;
        }
    }
    if (substring.length() != a.length()) {
        return removeRepetidos(substring);
    } else {
        return substring;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, substring;
    vector<int> lista;
    cin >> s;
    substring = removeRepetidos(s);
    if (substring.length() == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}