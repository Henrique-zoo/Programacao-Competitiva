#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct menor {
    bool operator() (pii a, pii b) {
        return get<0>(a) > get<0>(b);
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	int x;
	bool pode = false;
	cin >> n;
	vector<int> regioes;
    for (int i = 0; i < n; i++) {
        regioes.push_back(i);
    }
    int m = 0;
    int prod;
	while (!pode) {
        priority_queue<pii, vector<pii>, menor> fila;
		for (int i = 0; i < n; i++) {
            if (i+m > n-1) {
                prod = i + m*i - n;
            } else {
                prod = i + m*i;
            }
			fila.push({prod, regioes[prod]});
		}
        if (!fila.empty()) {
            tie(x, prod) = fila.top();
            cout << x << " " <<  prod << endl;
            fila.pop();
        }
		/*if (get<1>(fila.top()) == 13) {
			pode = true;
			break;
		}*/
        m++;
	}
	cout << m << endl;
}