#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40;
typedef long long LL;

vector<int> G[MAXN];
bool vis[MAXN];
int n, m, color[MAXN];

bool dfs(int u, int c) {
	color[u] = c;
	for (int v: G[u]) {
		if (color[v] == c) return false;
		if (color[v] == 3 - c) continue;
		if (!dfs(v, 3 - c)) return false;
	}
	return true;
}

void dfs(int u) {
	vis[u] = 1;
	for (int v: G[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

LL f1() {
	return 1LL << n;
}
LL f[1<<(MAXN/2+1)], g[MAXN];
void dfs1(int d, int mxd, LL s1, LL s2) {
	if (d == mxd) {
		f[s1]++;
		return;
	}
	dfs1(d+1, mxd, s1, s2);
	if ( !((1LL<<d) & s2) ) 
		dfs1(d+1, mxd, s1|(1LL<<d), s2|g[d]);
}
 
LL dfs2(int d, int mxd, LL s, LL t) {
	if (d == mxd) {
		s = (s & t) ^ t;
		return f[s];
	}
	LL ret = dfs2(d+1, mxd, s, t);
	if ( !(s & (1LL << d)) ) 
		ret += dfs2(d+1, mxd, s|g[d], t);
	return ret;
}

LL f2() {
	memset(f, 0, sizeof(f));
	int mid = n / 2;
	LL S0 = (1LL << mid) - 1;
	dfs1(0, mid, 0, 0);
	for (int i = 0; i < mid; ++i)
		for (int j = 0; j <= S0; ++j) 
			if (j & (1LL << i)) f[j] += f[j^(1LL<<i)];
	return dfs2(mid, n, 0, S0);
}

LL f3() {
	memset(vis, 0, sizeof(vis));
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		++k;
		dfs(i);
	}
	return 1LL << k;
}

LL f4() {
	return f2();
}

LL f5() {
	LL cnt1 = 0;
	for (int i = 0; i < n; ++i) if (G[i].size() == 0) ++cnt1;
	return 1LL << cnt1;
}

LL f6() {
	int k = 0;
	memset(color, 0, sizeof(color));
	for (int i = 0; i < n; ++i) {
		if (color[i]) continue;
		if (!dfs(i, 1)) return 0;
		++k;
	}
	return 1LL << k;
}

LL f7() {
	return f5();
}

LL f8() {
	LL cnt1 = 0;
	for (int i = 0; i < n; ++i) 
		if (G[i].size() == 0) ++cnt1;
	if (cnt1 == n) return 1LL << n;
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) g[i] = 1LL << i;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
		g[u] |= (1LL << v);
		g[v] |= (1LL << u);
	}
//	cout << f1() << " " << f2() << " " << f3() << " " << f2() << " " << f5() << " " << f6() << " " << f7() << " " << f8() << endl;
	cout << f1() - 2*f2() - f3()  + f5() + f6() + f7() - f8() << endl;
}
