#include <bits/stdc++.h>
using namespace std;

void kmp_pre(char x[], int m, int next[]) {
	int j = next[0] = -1;
	int i = 0;
	while (i < m) {
		while (j != -1 && x[i] != x[j]) j = next[j];
		next[++i] = ++j;
	}
}

bool KMP_count(char x[], int m, char y[], int n, int next[]) {
	int i = 0, j = 0, ans = 0;
	kmp_pre(x, m, next);
	while (i < n) {
		while (j != -1 && y[i] != x[j]) j = next[j];
		++i, ++j;
		if (j >= m) return true;
	}
	return false;
}

const int MAXN = 510;
const int MAXL = 2010;
char s[MAXN][MAXL];
int n, len[MAXN], Next[MAXL];
bool vis[MAXN];

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			vis[i] = false;
		}
		int ans = -1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (vis[j]) continue;
				if (KMP_count(s[j], len[j], s[i], len[i], Next)) vis[j] = true;
				else {
					ans = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", ++kase, ans == -1 ? -1 : ans + 1);
	}
}
