#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
vector<int> v[MAX];
vector<int> ans(MAX, 0);

int dfs(int i) {
    if(v[i].size() == 0)
        return ans[i];
    for (int filho : v[i])
        ans[i] += dfs(filho) + 1;
    return ans[i];
}

int main() {
    int n;
    cin >> n;
    int aux;
    for (int i = 1; i < n; i++) {
        cin >> aux;
        v[aux-1].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}