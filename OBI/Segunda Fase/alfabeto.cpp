#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, n;
    char aux;
    cin >> k >> n;
    unordered_set<char> alfabeto;
    while (k--) {
        cin >> aux;
        alfabeto.insert(aux);
    }

    bool possivel = true;
    while (n--) {
        cin >> aux;
        if (!alfabeto.count(aux))
            possivel = false;
    }
    
    if (possivel)
        cout << "S\n";
    else
        cout << "N\n";
        
    return 0;
}