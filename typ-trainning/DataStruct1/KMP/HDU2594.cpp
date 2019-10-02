#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

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
		scanf("%s", s+n+1);
		s[n] = '$';
		m = strlen(s+n+1);
		getFail(s, n+m+1, f);
		int x = f[n+m+1];;
		if (x) printf("%s %d\n", s+n+m+1-x, x); 
		else puts("0");
	}
}

