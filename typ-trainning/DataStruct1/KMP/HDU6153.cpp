#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void pre_EKMP(char x[], int m, int next[]) {
	next[0] = m;
	int j = 0;
	while (j+1 < m && x[j] == x[j+1]) ++j;
	next[1] = j;
	int k = 1;
	for (int i = 2; i < m; ++i) {
		int p = next[k] + k - 1;
		int L = next[i-k];
		if (i + L < p + 1) next[i] = L;
		else {
			j = max(0, p-i+1);
			while (i + j < m && x[i+j]==x[j]) ++j;
			next[i] = j;
			k = i;
		}
	}
}

void EKMP(char x[], int m, char y[], int n, int next[], int extend[]) {
	pre_EKMP(x, m, next);
	int j = 0;
	while (j < n && j < m && x[j] == y[j]) ++j;
	extend[0] = j;
	int k = 0;
	for (int i = 1; i < n; ++i) {
		int p = extend[k]+k-1;
		int L = next[i-k];
		if (i+L < p+1) extend[i] = L;
		else {
			j = max(0, p-i+1);
			while (i+j < n && j < m && y[i+j] == x[j]) ++j;
			extend[i] = j;
			k = i;
		}
	}
}

const LL mod = 1e9 + 7;
const int MAXN = 1000100;
char s1[MAXN], s2[MAXN];
int n, m, tmp[MAXN], extend[MAXN];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s %s", s1, s2);
		n = strlen(s1);
		reverse(s1, s1+n);
		m = strlen(s2);
		reverse(s2, s2+m);
		EKMP(s2, m, s1, n, tmp, extend);
		LL ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = (ans + 1LL * extend[i] * (extend[i]+1)/2) % mod;
		}
		cout << ans << endl;
	}
}
