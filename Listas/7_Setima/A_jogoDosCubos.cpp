#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, aux;
    cin >> n >> m;
    vector<int> cubos(n);
    for (int i = 0; i < n; i++)
        cin >> cubos[i];
    sort(cubos.begin(), cubos.end());
    for (int i = 0; i < m; i++) {
        cin >> aux;
        int l = 0, r = n-1;
        int mid, ans = -1;
        while (l <= r) {
            mid = (l+r)/2;
            if (cubos[mid] < aux)
                l = mid+1;
            else if (cubos[mid] >= aux) {
                if (cubos[mid] == aux)
                    ans = mid + 1;
                r = mid-1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}