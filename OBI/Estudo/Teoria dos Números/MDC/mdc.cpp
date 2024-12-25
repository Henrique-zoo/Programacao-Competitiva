#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b) {
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

int main() {
    int x, y;
    cin >> x >> y;
    int k = max(x, y);
    int w = min(x, y);
    cout << mdc(k, w) << endl;
}