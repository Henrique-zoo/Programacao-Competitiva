#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> pilhas;
    for (char container : s) {
        auto it = lower_bound(pilhas.begin(), pilhas.end(), container);
        if (it == pilhas.end()) {
            pilhas.push_back(container);
        } else {
            *it = container;
        }
    }
    cout << pilhas.size() << endl;
    return 0;
}