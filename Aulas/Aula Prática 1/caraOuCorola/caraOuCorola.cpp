#include <bits/stdc++.h>

using namespace std;

int main () {
    int x, y;
    cin>>x>>y;
    //scanf("%d", x);
    //scanf("%d", y);
    int soma = x+y;
    int probx = (float)x/soma * 100;
    int proby = (float)y/soma * 100;
    cout << probx << ' ' << proby <<'\n';
    return 0;
}