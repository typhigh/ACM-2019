#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
char s[MAXN];
int n, f[MAXN];
bool flag[MAXN];

void getFail(char* P, int *f, int m) {
	f[0] = f[1] = 0;
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
		n = strlen(s);
		getFail(s, f, n);
		memset(flag, 0, sizeof(flag));
		int t = f[n];
		int ans = 0;
		while (t) {
			if (t * 3 <= n)  flag[t] = true;
			t = f[t];
		}
		for (int i = n - 1; i > 1; --i) {
			int t = f[i];
			while (t) {
				if (flag[t] && t + i <= n && i >= 2 * t) ans = max(ans, t);
				t = f[t];
			}
		}
		cout << ans << endl;
	}
}
