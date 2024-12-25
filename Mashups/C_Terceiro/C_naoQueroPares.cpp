#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, aux;
        cin >> n;
        priority_queue<int> elementos;
        unordered_set<int> busca;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if (aux % 2 == 0 && !busca.count(aux)) {
                elementos.push(aux);
                busca.insert(aux);
            }
        }
        int count = 0;
        while (!elementos.empty()) {
            int x = elementos.top()/2;
            elementos.pop();
            count++;
            if (x % 2 == 0 && !busca.count(x)) {
                elementos.push(x);
                busca.insert(x);
            }
        }
        cout << count << endl;
    }
}