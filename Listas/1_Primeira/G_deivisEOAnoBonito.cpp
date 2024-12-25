#include <bits/stdc++.h>
using namespace std;

bool ehBonito(int a) {
    string b = to_string(a);
    for (int i = 0; i < b.length()-1; i++) {
        for (int j = i+1; j < b.length(); j++) {
            if (b[i] == b[j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int x;
    cin >> x;
    x++;
    while (!ehBonito(x)) {
        x++;
    }
    cout << x;
}