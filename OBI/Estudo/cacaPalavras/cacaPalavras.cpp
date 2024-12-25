#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m;
	char matriz[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cin >> matriz[i][j];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		string palavra;
        cin >> palavra;
		bool dentro = false;
        int t = palavra.length();
		char linha[t];
		char linha2[t];
		if (t > m) {
			cout << "NAO\n";
			continue;
		}
        // Horizontal
		for (int j = 0; j < n; j++) {
			for (int p = 0; p <= (m - t); p++) {
				for (int k = p; k < (t + p); k++) {
					linha[k-p] = matriz[j][k];
				}
                cout << linha << " ";
				if (palavra == linha || palavra == linha2) {
					dentro = true;
					break;
				}
			}
		}
        // Vertical
        for (int k = 0; k < m; k++) {
            for (int p = 0; p < n - t + 1; p++) {
                for (int j = p; j < (t + p); j++) {
                    linha[j-p] = matriz[j][k];
                    linha2[j-p] = matriz[n-1-j][k];
                }
                if (palavra == linha || palavra == linha2) {
                    dentro = true;
                    break;
                }
            }
        }
        for (int p = 0; p <= (n - t); p++) {
            if (dentro) {
                break;
            }
            for (int i = p; i < n-t+p; i++) {
                if (dentro) {
                    break;
                }
                for (int l = 0; l <= (m - t); l++) {
                    for (int j = l; j < t+l; j++) {
                        linha[j-l] = matriz[i+j-l][j];
                        linha2[j-l] = matriz[i+j-l][m-j-1];
                    }
                    if (palavra == linha || palavra == linha2) {
                        dentro = true;
                        break;
                    }
                }
            }
        }
        for (int p = 0; p <= (n - t); p++) {
            if (dentro) {
                break;
            }
            for (int i = p; i < n-t+p; i++) {
                if (dentro) {
                    break;
                }
                for (int l = 0; l <= (m - t); l++) {
                    for (int j = l; j < t+l; j++) {
                        linha[j-l] = matriz[n-1-j+l-p][j];
                        linha2[j-l] = matriz[n-1-j+l-p][m-j-1];
                    }
                    if (palavra == linha || palavra == linha2) {
                        dentro = true;
                        break;
                    }
                }
            }
        }
        if (dentro) {
            cout << "SIM\n";
        } else {
            cout << "NAO\n";
        }
    }
	return 0;
}