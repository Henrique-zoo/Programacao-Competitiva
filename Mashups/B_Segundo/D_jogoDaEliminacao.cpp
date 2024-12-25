#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, resto, count = 0, aux, crianca;
    queue<int> criancas, ans;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        criancas.push(i);
    for (int i = 0; i < k; i++) {
        cin >> aux;
        bool encontrou = false;
        resto = aux % (n-i);
        while (!encontrou) {
            crianca = criancas.front();
            criancas.pop();
            if (count == resto) {
                ans.push(crianca);
                encontrou = true;
                count = 0;
            } else {
                count++;
                criancas.push(crianca);
            }
        }
    }
    while (!ans.empty()) {
        cout << ans.front() << " ";
        if (ans.size() == 1)
            cout << '\n';
        ans.pop();
    }
    return 0;
}