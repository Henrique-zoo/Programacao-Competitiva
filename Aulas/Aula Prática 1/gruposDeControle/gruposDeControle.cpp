#include <bits/stdc++.h>

int main() {
    long long int n, i, k;
    scanf("%lld", &n);
    for (i = n; i > 1; i/2) {
        if (i % 2 != 0) {
            break;
        }
    }
    printf("%lld\n", i);

    return 0;
}