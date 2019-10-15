#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
	if (a < b) return a;
	return (a * 2 + b) / 3;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int c, m, x;
		scanf("%d %d %d", &c, &m, &x);
		if (c > m) swap(c, m);
		x += m - c;
		m = c;
		cout << solve(m, x) << endl;
	}
}
