#include <bits/stdc++.h>
using namespace std;
int a1, a2, k1, k2, n, ans1, ans2;

void solve() {
	int lim = a1 * (k1 - 1) + a2 * (k2 - 1);
	if (n < lim) ans1 = 0;
	else ans1 = n - lim;
	if (k1 > k2) {
		swap(k1, k2);
		swap(a1, a2);
	}
	int L = min(a1, n / k1);
	n -= L * k1;
	int R = min(a2, n / k2);
	ans2 = L + R;
}
int main() {
	cin >> a1 >> a2 >> k1 >> k2 >> n;
//	int lim = a1 * (k1 - 1) + a2 * (k2 - 1);
	solve();
	cout << ans1 << " " << ans2 << endl;
}
