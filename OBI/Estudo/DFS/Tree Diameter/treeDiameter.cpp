#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
vector<int> v[MAX];
int ans = 0;

int dfs(int i, int p, int h) {
    int maior = h;
    int segundo = 0;
    for(int filho : v[i]) {
        if (filho != p) {
            int temp = dfs(filho, i, h+1);
            if(temp >= maior) {
                segundo = maior;
                maior = temp;
            } else if (temp > segundo)
                segundo = temp;
        }
    }
    ans = max(ans, maior+segundo - 2*h);
    return maior;
}

int main() {
    int n;
    cin >> n;
    int de, para;
    for (int i = 0; i < n-1; i++) {
        cin >> de >> para;
        v[de-1].push_back(para-1);
        v[para-1].push_back(de-1);
    }
    dfs(0, -1 ,0);
    cout << ans << endl;
}