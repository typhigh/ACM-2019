#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500100;
const int SQRT = sqrt(MAXN+0.5); 
int sum[SQRT][SQRT], a[MAXN];

int main() {
	int q, op, x, y;
	cin >> q;
	while (q--) {
		cin >> op >> x >> y;
		if (op == 1) {
			a[x] += y;
			for (int i = 1; i < SQRT; ++i) 
				sum[i][x%i] += y;
		} else if (op == 2) {
			int ans = 0;
			if (x < SQRT) {
				ans = sum[x][y];
			} else {
				for (int i = y; i < MAXN; i += x) {
					ans += a[i];
				}
			}
			cout << ans << endl;
		}
	}
}
