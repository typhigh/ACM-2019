#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400010;
int n, m, I, a[MAXN], b[MAXN];

int solve() {
	int L = I * 8 / n;
	if (L > 20) return 0;
	L = 1 << L;
	if (L >= m) return 0;
	int l = 0, r = L - 1;
	int al = lower_bound(a, a + n, b[l]) - a;
	int ar = upper_bound(a, a + n, b[r]) - a;
	int ans = n - (ar - al);
	for (l = 1; l < m - L; ++l) {
		while(al + 1 < n && a[al] == a[al+1]) ++al;
		++al;
		while(ar + 1 < n && a[ar] == a[ar+1]) ++ar;
		++ar;
		ans = min(ans, n - (ar - al));
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &I);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	memcpy(b, a, sizeof(a));
	m = unique(b, b + n) - b;
	printf("%d\n", solve());
}
