#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
        
    sort(v.begin(), v.end());
    
    int l = 0, r = n - 1;
    pair<int, int> ans;
    while (l < r) {
        int soma = v[l] + v[r];
        if (soma < m)
            l++;
        else if (soma > m)
            r--;
        else {
            ans = {l, r};
            l++;
            r--;
        }
    }
    cout << v[ans.first] << " " << v[ans.second] << endl;
}
