#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, aux;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());

    int i = -1, j = n-1;
    while (j > i) {
        while (i+1 < j && v[i+1] + v[j])
    } 
}