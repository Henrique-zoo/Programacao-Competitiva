#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	stack<char> parenteses;
	vector<char> p;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (parenteses.empty())
			parenteses.push(s[i]);
		else {
			if (parenteses.top() == '(' && s[i] == ')')
				parenteses.pop();
			else
				parenteses.push(s[i]);
		}
	}
	while (!parenteses.empty()) {
		p.push_back(parenteses.top());
		parenteses.pop();
	}
	if (p.size() == 0 || (p.size() == 2 && p[1] != p[0])) {
		cout << "Yes\n";
	} else {
        cout << "No\n";
    }
    return 0;
}