#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> triple;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        cout << min(x,y) << " " << max(x,y) << endl;
    }
}