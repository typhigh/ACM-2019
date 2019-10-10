#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int h, n, p[MAXN];

int solve() {
	int ans = 0;
	for (int i = 0, cur = h; i < n - 1; ) {
		if (p[i] == p[i+1]+1) {
			if (i + 1 >= n - 1) break;
			if (p[i+2] + 1 != p[i+1]) {
				++ans;
				++i;
			} else {
				i += 2;
			}
		} else {
			p[i] = p[i+1]+1;
		}
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &h, &n);
		for (int i = 0; i < n; ++i) scanf("%d", p + i);
		p[n++] = 0;		
		printf("%d\n", solve());
	}
}
