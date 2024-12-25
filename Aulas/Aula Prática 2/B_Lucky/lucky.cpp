#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    char zero = '0';
    for (int i = 0; i < t; i++) {
        int sum1 = 0;
        int sum2 = 0;
        string str;
        cin >> str;
        for (int j = 0; j < 3; j++) {
            sum1 += str[j] - zero;
            sum2 += str[5-j] - zero;
        }
        if (sum1 == sum2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}