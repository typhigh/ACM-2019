#include <bits/stdc++.h>
using namespace std;
int n, cnt[30], s[110];

int low(int x) {
	for (int i = 0 ; i < 30; ++i) if ((1 << i) & x) return i;
	while(1);
}

bool solve() {
	for (int i = 0; i < n; ++i) {
		int v = low(s[i]);
		if (v > 11) continue;
		if (v == 11) return true;
		if (cnt[v]) {
			cnt[v] = 0;
			s[i] = s[i] << 1;
			--i;
		} else 
			cnt[v]++;
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) scanf("%d", s + i);
		if (solve()) puts("YES");
		else puts("NO");
	}
}
