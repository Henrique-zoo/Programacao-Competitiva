#include <iostream>
using namespace std;

int lower_bound(int x, vector<int> v) {
    int l = 0, r = v.size()-1, meio, ans = -1;
    while (l <= r) {
        meio = (l+r)/2;
        if (v[meio] >= x) {
            ans = meio;
            r = meio - 1;
        } else {
            l = meio + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {1,4,6,7,9,17,89,1002};
    int chave;
    cin >> chave;
    cout << v[lower_bound(chave, v)] << endl;
}