#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll x, y, z, m, n;
    char cupim;
    cin >> x >> y >> z;
    cin >> m >> n;
    map<char, int> cupins = {
        {'F', x},
        {'A', y},
        {'R', z}
    };
    vector<ll> tamanduas(1, m);

    while (n--) {
        cin >> cupim;
        ll peso = cupins[cupim];
        bool consumido = false;
        for (auto& tamandua : tamanduas) {
            if (tamandua >= peso) {
                tamandua -= peso;
                consumido = true;
                break;
            }
        }
        if (!consumido) {
            tamanduas.push_back(m - peso);
        }
    }

    cout << tamanduas.size() << endl;

    return 0;
}
