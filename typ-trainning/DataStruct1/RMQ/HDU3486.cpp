#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, k, d[MAXN][20];

void init() {
	for (int k = 1; (1<<k) <= n; ++k) 
		for (int i = 0; i + (1<<k) - 1 < n; ++i)
			d[i][k] = max(d[i][k-1], d[i+(1<<k-1)][k-1]);
}

int query(int l, int r) {
	int k = 0;
	while ((1<<k) <= r - l + 1) ++k;
	return max(d[l][k-1], d[r-(1<<k-1)+1][k-1]);
}

int solve() {
	for (int lm = 1, rm; lm <= n; lm = rm + 1) {
		int len = n / lm;
		rm = (n / len);
		int sum = 0;
		for (int i = 1, j = 0; i <= rm; ++i, j += len) {
			sum += query(j, j+len-1);
			if (sum > k) 
				return max(lm, i);
		}
	}
	while(1);
}
int main() {
	while (~scanf("%d%d", &n, &k) && ~n && ~k) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &d[i][0]);
			sum += d[i][0];
		}
		if (sum <= k) {
			puts("-1");
			continue;
		}
		init();
		printf("%d\n", solve());
	}
}
