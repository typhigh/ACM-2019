#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
char s[MAXN];
int f[MAXN];

void getFail(char *P, int *f, int m) {
	f[0] = 0, f[1] = 0;
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
		scanf("%s", s);
		int m = strlen(s);
		getFail(s, f, m);
		if (f[m] && m % (m-f[m]) == 0) puts("0");
		else printf("%d\n", (m - f[m]) - m % (m - f[m]));
	}
}
