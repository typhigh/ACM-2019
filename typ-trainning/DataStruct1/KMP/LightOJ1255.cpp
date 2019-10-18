#include <bits/stdc++.h>
using namespace std;

void getFail(char* P, int *f) {
	int m = strlen(P);
	f[0] = 0; f[1] = 0;
	for (int i = 1; i < m; ++i) {
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j] ? j+1 : 0;
	}
}

int find(char* T, char* P, int *f) {
	int ret = 0;
	int n = strlen(T), m = strlen(P);
	getFail(P, f);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j && P[j] != T[i]) j = f[j];
		if (P[j] == T[i]) ++j;
		if (j == m) ++ret;
	}
	return ret;
}

const int MAXN = 1001000;
char Text[MAXN], P[MAXN];
int f[MAXN];
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%s %s", Text, P); 
		cout << "Case " << (++kase) << ": " << find(Text, P, f) << endl;
	}
}
