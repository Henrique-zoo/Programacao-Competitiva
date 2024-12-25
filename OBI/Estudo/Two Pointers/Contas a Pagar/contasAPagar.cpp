#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, a, f, p;
    int soma = 0;
    int count = 0;
    vector<int> v;
    cin >> d >> a >> f >> p;
    v.push_back(a);
    v.push_back(f);
    v.push_back(p);
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; i++) {
        soma += v[i];
        if (soma <= d)
            count += 1;
    }
    cout << count << endl;
}