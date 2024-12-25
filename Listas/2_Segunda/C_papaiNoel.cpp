#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	int x, n, maior;
	char op;
	stack<pii> saco;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> op >> x;
		if (op == 'A') {
			if (saco.empty())
				maior = x;
			else
				maior = max(x, saco.top().second);
			saco.push({x, maior});
		} else if (op == 'V') {
			if (!saco.empty())
				cout << saco.top().second << "\n";
			else
				cout << "0\n";
		} else {
			if (!saco.empty())
				saco.pop();
		}
    }
	return 0;
}