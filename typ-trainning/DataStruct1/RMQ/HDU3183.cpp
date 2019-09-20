#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;

char s[MAXN];
int n, m, d[MAXN][15], pos[MAXN][15];

void init() {
	for (int i = 0; i < n; ++i) {
		d[i][0] = s[i]-'0';
		pos[i][0] = i;
	}
	for (int k = 1; (1 << k) <= n; ++k) 
		for (int i = 0; i + (1<<k) - 1 < n; ++i) {
			d[i][k] = d[i][k-1];
			pos[i][k] = pos[i][k-1];
			if (d[i][k] > d[i+(1<<k-1)][k-1]) {
				d[i][k] = d[i+(1<<k-1)][k-1];
				pos[i][k] = pos[i+(1<<k-1)][k-1];
			}
		}
}

int query(int l, int r) {
	int k = 0;
	while ((1<<k) <= r-l+1) ++k;
	int ans = pos[l][k-1];
	if (d[l][k-1] > d[r-(1<<k-1)+1][k-1]) 
		ans = pos[r-(1<<k-1)+1][k-1];
	return ans;
}

int cur;
char ans[MAXN];

int solve(int l, int m) {
//	cout << l << " " << m << endl;
	if (l == n) return m;
	int r = min(n - 1, m + l);
	int p = query(l, r);
//	cout << l << "and " << p << endl;
	ans[cur++] = s[p];
	m -= p - l;
	return solve(p+1, m);
}

void Debug() {
	int l, r;
	while (cin >> l >> r) {
		int p = query(l, r);
		cout << p << endl;
	}
}

int main() {
	while (~scanf("%s%d", s, &m)) {	
		//Debug();
		n = strlen(s);
		if (n == m) {
			puts("0");
			continue;
		}
		init();
//		Debug();
		cur = 0;
		int x = solve(0, m);
//		cout << x << endl;
		cur -= x;
		ans[cur] = 0;
		int id;
		for (id = 0; id < cur - 1 && ans[id] == '0'; ++id);
		printf("%s\n", ans+id);
	}
}
