#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, r, a[MAXN];

int solve() {
	for (int cnt = 1; cnt < n; ++cnt) {
		if ((long long) a[n-cnt-1] <= 1LL * cnt * r) 
			return cnt;
	}
	return n;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &r);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		sort(a, a + n);
		n = unique(a, a + n) - a;
		printf("%d\n", solve()); 
	}
}
