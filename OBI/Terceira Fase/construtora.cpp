#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> tupla;
int k = 0, n;

priority_queue<tupla, vector<tupla>, greater<tupla>> sequencias(vector<int> & predios) {
    priority_queue<tupla, vector<tupla>, greater<tupla>> pq;
    int l = 0, r = 0, tamanho = 0;
    while (r <= n) {
        if (predios[l] == predios[r]) {
            r++;
            tamanho++;
        } else if ((predios[l] != predios[r]) || (r == n-1)) {
            pq.push({predios[l], tamanho, l, r});
            l = r;
            tamanho = 0;
        }
    }
    return pq;
}

void atualiza(priority_queue<tupla, vector<tupla>, greater<tupla>> pq, vector<int> & predios) {
    if (pq.size() == 1)
        return;
    k++;
    int t, tS, l, r;
    tie(t, tS, l , r) = pq.top();
    pq.pop();

    for (int i = l; i < r; i++)
        predios[i]++;

    pq = sequencias(predios);
    atualiza(pq, predios);
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> predios(n);

    for (int i = 0; i < n; i++)
        cin >> predios[i];

    priority_queue<tupla, vector<tupla>, greater<tupla>> pq = sequencias(predios);
    atualiza(pq, predios);
    cout << k << endl;

    return 0;
}