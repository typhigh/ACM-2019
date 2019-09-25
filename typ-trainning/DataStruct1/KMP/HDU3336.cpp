#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
char P[MAXN];
int n, f[MAXN];

void getFail(char *P, int m, int *f) {
	f[0] = 0;
	f[1] = 0;
	for (int i = 1; i < m; ++i) {
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j] ? j+1 : 0;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", P);
		getFail(P, n, f);
		int ans = n;
		for (int i = 1; i <= n; ++i) 
			ans += f[i] > 0;
	 	ans %= 10007;
		printf("%d\n", ans);
	}
}
