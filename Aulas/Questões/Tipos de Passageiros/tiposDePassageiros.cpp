#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> triple;

struct menor_triple {
    bool operator() (triple a, triple b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        else
            return get<0>(a) > get<0>(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ocupados, id, b, w;
    string passageiros;

    priority_queue<triple> introvertidos;

    priority_queue<triple, vector<triple>, menor_triple> extrovertidos;

    cin >> n;
    cin >> passageiros;
    for (int i = 0; i < n; i++) {
        cin >> w;
        introvertidos.push({0, w, i+1});
        extrovertidos.push({0, w, i+1});
    }
    for (int i = 0; i < 2*n; i++) {
        if (passageiros[i] == '0') {
            tie(ocupados, w, id) = introvertidos.top();
            introvertidos.pop();
            extrovertidos.push({ocupados+1, w, id});
        } else {
            tie(ocupados, w, id) = extrovertidos.top();
            extrovertidos.pop();
            introvertidos.push({ocupados+1, w, id});
        }
        cout << id << " ";
    }
}