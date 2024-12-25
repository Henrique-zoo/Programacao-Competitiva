#include <bits/stdc++.h>

int main() {
    int n, a;
    std::cin >> n;
    int maior = 0; int totalDes = 0; int totalIg = 0;
    for (int i = n; i > 0; i--) {
        std::cin >> a;
        totalDes += a;
        if (a > maior) {
            maior = a;
        }
    }
    totalIg = maior*n;
    std::cout << totalIg - totalDes;
    return 0;
}