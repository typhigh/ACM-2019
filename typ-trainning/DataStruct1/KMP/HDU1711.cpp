#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000100;
int n, m, a[MAXN], b[MAXN], f[MAXN];

void getFail(int* P, int m, int *f) {
	f[0] = 0; f[1] = 0;
	for (int i = 1; i < m; ++i) {
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j] ? j + 1 : 0;
	}
}

int find(int *T, int *P, int n, int m, int *f) {
	getFail(P, m, f);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j && P[j] != T[i]) j = f[j];
		if (P[j] == T[i]) ++j;
		if (j == m) {
			return i-m+1;
		}
	}
	return -2;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 0; i < m; ++i) scanf("%d", b + i);
		cout << find(a, b, n, m, f) + 1<< endl;
	}
}
