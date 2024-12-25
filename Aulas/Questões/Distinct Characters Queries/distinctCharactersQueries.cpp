#include <bits/stdc++.h>
using namespace std;

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int t, q, op, pos, f;
    char c;
    vector<set<int>> qtd(26);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        qtd[s[i]-'a'].insert(i);
    }
    cin >> t;
    while (t--) {
        cin >> op;
        if (op == 1) {
            cin >> pos >> c;
            qtd[s[pos-1]-'a'].erase(pos-1);
            s[pos-1] = c;
            qtd[c-'a'].insert(pos-1);
        } else {
            cin >> pos >> f;
            set<int>::iterator p;
            int count = 0;
            pos--; f--;
            for (int i = 0; i < qtd.size(); i++) {
                if (!qtd[i].size())
                    continue;
                p = qtd[i].lower_bound(pos);
                if (p != qtd[i].end() && *p <= f)
                    count++;
            }
            cout << count << endl;
        }
    }
    return 0;
}