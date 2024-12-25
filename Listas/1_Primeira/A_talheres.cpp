#include <bits/stdc++.h>

int main() {
    int n, g, f, c, count;
    std::cin >> n >> g >> f >> c;
    count = c;
    if (g <= f) {
        count += g;
    } else {
        count += f;
    }
    if (count > n) {
        count = n;
    }
    std::cout << count;
    return 0;
}