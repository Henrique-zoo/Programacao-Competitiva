#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int maximo = 0;
    int tempo = 0;
    int comeco = 0;

    for (int fim = 0; fim < n; ++fim) {
        tempo += a[fim];

        while (tempo > t) {
            tempo -= a[comeco];
            ++comeco;
        }

        maximo = max(maximo, fim - comeco + 1);
    }

    cout << maximo << endl;
    return 0;
}
