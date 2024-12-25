#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	bool falsificada = false;
	int n = s.length();
	if (n == 8) {

		for (int i = 0; i < 3; i++)
			if (s[i] < 'A' || s[i] > 'Z')
				falsificada = true;

		if (s[3] != '-')
			falsificada = true;

		for (int i = 4; i < 8; i++)
			if (s[i] < '0' || s[i] > '9')
				falsificada = true;

	} else if (n == 7) {

		for (int i = 0; i < 3; i++)
			if (s[i] < 'A' || s[i] > 'Z')
				falsificada = true;

		if (s[3] < '0' || s[3] > '9')
			falsificada = true;

		if (s[4] < 'A' || s[4] > 'Z')
			falsificada = true;

		for (int i = 5; i < 7; i++)
			if (s[i] < '0' || s[i] > '9')
				falsificada = true;

	} else {
		falsificada = true;
	}

	if (falsificada)
		cout << 0;
	else
		if (n == 8)
			cout << 1;
		else
			cout << 2;
	cout << endl;

}