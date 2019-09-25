#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;

char s[MAXN];
int n, m, f[MAXN];

void getFail(char* P, int m, int* f) {
	f[0] = f[1] = 0;
	for (int i = 1; i < m; ++i) {
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j] ? j+1 : 0;
	}
}

int main() {
	while (~scanf("%s", s)) {
		n = strlen(s);
		scanf("%s", s + n);
		m = strlen(s+n);
		getFail(s, n+m, f);
		int x = f[n+m];
		x = min(x, min(n, m));
		if (x) printf("%s %d", s+n+m-x, x); 
		else puts("0");
	}
}

