#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m, C[MAXN];

int lowbit(int x) {
	return x & -x;
}

int sum(int x) {
	int ret = 0;
	while (x > 0) {
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d) {
	while (x <= n) {
		C[x] += d;
		x += lowbit(x);
	}
}

void init() {
	for (int i = 0; i <= n; ++i) C[i] = 0;
}

char s[20];
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case %d:\n", ++kase);
		scanf("%d", &n);		
		init();
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			add(i, x);
		}
		while (~scanf("%s", s)) {
			int x, y;
			if (s[0] == 'E') break;
			else if (s[0] == 'A') {
				scanf("%d %d", &x, &y);
				add(x, y);
			} else if (s[0] == 'S') {
				scanf("%d %d", &x, &y);
				add(x, -y);
			} else if (s[0] == 'Q') {
				scanf("%d %d", &x, &y);
				int ans = sum(y) - sum(x-1);
				printf("%d\n", ans);
			}
		}
	}
}
			
