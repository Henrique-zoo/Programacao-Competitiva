#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> facesPintadas(4);
    facesPintadas[0] = (n-2)*(n-2)*(n-2);
    facesPintadas[1] = (n-2)*(n-2)*6;
    facesPintadas[2] = 2*(n-2)*4 + 2*(n-2)*2;
    facesPintadas[3] = 8;
    for (int i = 0; i < 4; i++)
        cout << facesPintadas[i] << endl;
        
    return 0;
}