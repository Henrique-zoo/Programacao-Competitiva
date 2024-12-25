#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, k, iMenor;
    cin >>  a;
    cin >> b;
    cin >> c;
    long long int menork = pow(10, 28);
    for (int i = 1; i <= 99; i++) {
        k = fabs(i-a) + pow(fabs(i-b), 2) + pow(fabs(i-c), 3);
        if (k < menork) {
            menork = k;
            iMenor = i;
        }
    }
    cout << iMenor;

    return 0;
}