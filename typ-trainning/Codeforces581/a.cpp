#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int x = (n + 1) / 2;
	int sub = (n & 1);
	for (int i = 1; i < s.size(); ++i) 
		if (s[i] == '1') {
			sub = 0;
			break;
		}
	x -= sub;
	cout << x << endl;
}
