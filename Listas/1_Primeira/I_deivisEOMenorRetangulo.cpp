#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x;
    vector<int> y;
    long long int menorx = 99999999999;
    long long int menory = 9999999999;
    int maiorx = 0;
    int maiory = 0;
    for (int i = 0; i < n; i++) {
        string linha;
        cin >> linha;
        for (int j = 0; j < m; j++) {
            int a = linha[j] - '0';
            if (a == 1) {
                if (j > maiorx) {
                    maiorx = j;
                } else if (j < menorx) {
                    menorx = j;
                }
                if (i > maiory) {
                    maiory = i;
                } else if (i < menory) {
                    menory = i;
                }
            }
        }
    }
    if (menorx == 99999999999) {
        cout << "0x0";
    } else {
        cout << maiorx - menorx + 1 << "x" << maiory - menory + 1;
    }
}