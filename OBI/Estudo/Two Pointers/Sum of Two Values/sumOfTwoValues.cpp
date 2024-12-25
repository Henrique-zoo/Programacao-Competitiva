#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> v;
    for (int i = 1; i <= n; i++) {
        int aux;
        cin >> aux;
        v.push_back({aux, i});
    }
    sort(v.begin(), v.end());
    int i=-1,j=n-1;
    while (j > i) {
        while (i+1 < j && v[i+1].first + v[j].first <= x) {
            i++;
        }
        if (i >= 0 && v[i].first + v[j].first == x) {
            cout << v[i].second << " " << v[j].second << endl;
            return 0;
        }
        j--;
    }
    cout << "IMPOSSIBLE\n";
}