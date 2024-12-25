#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        vector<int> x;
        vector<int> a;
        cin >> n;
        for (int j = 0; j < n-1; j++) {
            int xi;
            cin >> xi;
            x.push_back(xi);
        }
        a.push_back(9999999);
        for (int k = 0; k < n; k++) {
            a.push_back(a[k] + x[k]);
        }
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << "\n";
    }
}