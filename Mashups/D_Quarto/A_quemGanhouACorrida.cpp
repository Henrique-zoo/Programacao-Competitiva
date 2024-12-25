#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, aux, frente = 0;
		cin >> a;
		for (int i = 0; i < 3; i++) {
			cin >> aux;
			if (aux > a)
				frente++;
		}
		cout << frente << endl;
	}
}