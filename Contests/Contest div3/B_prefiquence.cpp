#include <bits/stdc++.h>
using namespace std;

vector<string> substrings(string a, int m) {
    vector<string> lista;
    for (int k = 1; k <= m; k++) {
        for (int j = 0; j <= a.length()-k; j++) {
            string substring = "";
            for (int w = 0; w < k; w++) {
                substring += a[w+j];
            }
            lista.push_back(substring);
        }
    } 
    return lista;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        string a, b;
        cin >> n >> m;
        cin >> a >> b;
        int c = min(n, m);
        vector<string> subA = substrings(a, c);
        int maior = 0;
        

        for (int j = 0; j < subA.size(); j++) {
            int count = 0;
            for (int k = 0; k < subA[j].length(); k++) {
                auto it = find(b.begin(), b.end(), subA[j][k]);
                if (it != b.end()) {
                    count ++;
                }
            }
            if (count > maior) {
                maior = count;
            }
        }
        cout << maior << "\n";
    }
}