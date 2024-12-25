#include <bits/stdc++.h>

using namespace std;


bool podeDar(const vector<int>& chocolates, int m, int qtd) {
    int count = 0;
    for (int chocolate : chocolates)
        count += chocolate / qtd;

    return count >= m;
}

int chocPorMae(int n, int m, vector<int>& chocolates) {
    int l = 1;
    int r = chocolates[0];
    int melhor = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (podeDar(chocolates, m, mid)) {
            melhor = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return melhor;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> chocolates(n);
    for (int i = 0; i < n; ++i)
        cin >> chocolates[i];

    sort(chocolates.rbegin(), chocolates.rend());
    cout << chocPorMae(n, m, chocolates) << endl;

    return 0;
}
