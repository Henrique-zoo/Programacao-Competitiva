#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int count = 0;
        if (b > a)
            count += 1;
        if (c > a)
            count += 1;
        if (d > a)
            count += 1;
        cout << count << "\n";
    }
}