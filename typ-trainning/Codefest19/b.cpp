#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2050;
map<int, int> cnt;
int n, a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int r;
	for (r =  n - 1; r >= 0; --r) {
		if (cnt.count(a[r])) break;
		cnt[a[r]] = 1;
	}
	int l = 0;
	int ans =  r - l + 1;
	if (ans == 0) {
		printf("%d\n", ans);
		return 0;
	}
	for (l = 0; l < r; ++l) {
		int c = cnt[a[l]] + 1;
		cnt[a[l]] = c;
		// cout << " " << l <<  c << endl;
		while (r < n - 1 && cnt[a[l]] > 1) {
			++r;
			--cnt[a[r]];
		}
		if (r == n - 1 && cnt[a[l]] > 1) break;
		ans = min(ans, r - l);
	}
	printf("%d\n", ans);
}
		
		
