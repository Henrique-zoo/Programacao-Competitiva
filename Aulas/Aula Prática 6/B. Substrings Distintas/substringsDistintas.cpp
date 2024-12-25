#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    unordered_set<string> substrings;
    string substring = "";
    substrings.insert(substring);
    while (r < n) {
        if (s[l] == s[r])
            substring += s[r++];
        else {
            substring = "";
            l++;
        }
        substrings.insert(substring);
    }
    cout << substrings.size()-1 << endl;
}