#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, vivos;
	queue<pair<int,int>> qp;
	cin >> n >> q;
	vector<string> vs(n);
	vector<vector<int>> matriz(n+2, vector<int>(n+2,0));
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
	}
	for (int i = 1; i <= n; i++) {
		string sAux = vs[i-1];
		for (int j = 1; j <= n; j++) {
			matriz[i][j] = sAux[j-1]-'0';
		}
	}
	while (q--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				vivos = 0;
				if (matriz[i-1][j-1])
					vivos++;
				if (matriz[i-1][j])
					vivos++;
				if (matriz[i-1][j+1])
					vivos++;
				if (matriz[i][j-1])
					vivos++;
				if (matriz[i][j+1])
					vivos++;
				if (matriz[i+1][j-1])
					vivos++;
				if (matriz[i+1][j])
					vivos++;
				if (matriz[i+1][j+1])
					vivos++;

				if (matriz[i][j] == 0 && vivos == 3)
					qp.push({i,j});
				else if ((matriz[i][j] == 1) && (vivos != 2 && vivos != 3))
					qp.push({i,j});
			}
		}
		while(!qp.empty()) {
			pair<int,int> par = qp.front();
			qp.pop();
			matriz[par.first][par.second]^=1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << matriz[i][j];
		cout << endl;
	}
}