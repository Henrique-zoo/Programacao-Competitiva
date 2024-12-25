#include <bits/stdc++.h>
using namespace std;
int n;

pair<int, int> two_sum(vector<int>& v, int s) {
    int l = 0, r = n-1;

    while (l < r) {
        if (v[l] + v[r] < s)
            l++;
        else if (v[l] + v[r] > s)
            r--;
        else
            break;
    }
    
    return {l, r};
}

int main() {
    int soma, i , j;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];
    cin >> soma;
    sorted(v.begin(), v.end());
    tie(i, j) = two_sum(v, soma);

    if (i == j)
        cout << "No\n";
    else
        cout << "Yes\n" << i << ", " << j << endl;
}