#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n, aux;
    int soma = 0;
    cin >> n;
    while (n--) {
        cin >> aux;
        if (aux == 0) {
            v.pop_back();
        } else {
            v.push_back(aux);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        soma += v[i];
    }
    cout << soma << endl;
}