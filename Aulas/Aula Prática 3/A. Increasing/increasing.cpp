#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, a, x;
	cin >> n;
	while (n--) {
		cin >> a;
		set<int> elementos;
		int count = 0;
		for (int i = 0; i < a; i++) {
			cin >> x;
			elementos.insert(x);
			count ++;
		}
		if (count == elementos.size()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
    return 0;
}