#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, m, k;

LL solve() {
	/*
	if (m <= k) {
		LL ans = (k - 1) % (n - m + 1);
		for (int i = 2; i <= m; ++i) 
			ans = (ans + k) % (n - m + i);
		return ans + 1;
	}
	*/
	// k < m <= n
	if (k == 1) return m;
	LL ans = (k - 1) % (n - m + 1);
	// n - m + k + 1;i
	for (LL i = 2, j; i <= m; i = i + j) {
		j = (n - m + i - ans) / k;
		if (j <= 0) j = 1;
		j = min(j, m - i + 1);
		ans = (ans + j * k) % (n - m + i + j - 1);
//		cout << i << " " << j << " " << ans << endl;
	}
	return ans + 1;
}

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		cin >> n >> m >> k;
		cout << "Case #" << ++kase << ": " << solve() << endl;
	}
}
