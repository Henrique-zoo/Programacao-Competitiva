#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    int aux = 1;
    vector<int> contests;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        contests.push_back(a);
    }
    sort(contests.begin(), contests.end());
    for (int i = 0; i < n; i++) {
        if (contests[i] >= aux) {
            aux ++;
        }
    }
    cout << aux - 1;
}