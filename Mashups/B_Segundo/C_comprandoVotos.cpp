#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> votos;
    int n, aux, sanaduva, vot;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        if (i == 0) {
            sanaduva = aux;
        } else {
            votos.push(aux);
        }
    }
    int count = 0;
    while (votos.top() >= sanaduva) {
        vot = votos.top();
        votos.pop();
        votos.push(vot-1);
        count++;
        sanaduva++;
    }
    cout << count << endl;
}