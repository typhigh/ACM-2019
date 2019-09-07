#include <bits/stdc++.h>
using namespace std;
int n, x;

int solve() {
    cin >> n >> x;
	int maxa = 0, maxd = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		maxa = max(a, maxa);
		maxd = max(a - b, maxd);
	}
	if (maxa >= x) return 1;
	if (maxd <= 0) return -1;
	int cnt = (x - maxa) / maxd;
	if (1LL * cnt * maxd + maxa < x) ++cnt;
	return cnt + 1;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cout << solve() << endl;
	}
}

		

