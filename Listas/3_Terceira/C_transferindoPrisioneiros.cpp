#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, t, c, aux;
    cin >> n >> t >> c;
    int count = 0;
    int countGrupos = 0;
    while (n--) {
        cin >> aux;
        if (aux > t)
            count = 0;
        else
            count++;
        if (count == c) {
            countGrupos++;
            count--;
        }
    }
    cout << countGrupos << endl;
}