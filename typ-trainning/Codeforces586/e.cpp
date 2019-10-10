#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;

vector<int> G[MAXN], g[MAXN];
vector<int> edges;
int n, m, s, dfs_clock, dfn[MAXN], low[MAXN], a[MAXN];
bool bridge[MAXN*2];
LL ans, M, mx[MAXN], bew[MAXN];

void add(int x, int y) {
	G[x].push_back(edges.size());
	edges.push_back(y);
}

void tarjan(int x, int in_edge) {
	dfn[x] = low[x] = ++dfs_clock;
	for (int i : G[x]) {
		int v = edges[i];
		if (!dfn[v]) {
			tarjan(v, i);
			low[x] = min(low[x], low[v]);
			if (low[v] > dfn[x]) 
				bridge[i] = bridge[i^1] = true;
		} else if (i != (in_edge ^ 1)) 
			low[x] = min(low[x], dfn[v]);
	}
}


int be[MAXN], Size[MAXN];
bool cir[MAXN];
void Be(int u, int k) {
	be[u] = k;
	bew[k] += a[u];
	Size[k]++;
	for (int i : G[u]) {
		int v = edges[i];
		if (!bridge[i] && !be[v]) Be(v, k);
	}
}

void DFS(int u, int fa) {
	cir[u] = Size[u] > 1;
	for (int v : g[u]) {
		if (v == fa) continue;
		DFS(v, u);
		cir[u] |= cir[v];
		mx[u] = max(mx[v], mx[u]);
	}
	mx[u] += bew[u];
	if (cir[u]) ans += bew[u];
	else M = max(M, mx[u]);
}

LL solve() {
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, 0);
	for (int i = 1, k = 0; i <= n; ++i) if (!be[i]) Be(i, ++k);
	for (int u = 1; u <= n; ++u) 
		for (int i : G[u]) {
			int v = edges[i];
			if (be[u] != be[v]) g[be[u]].push_back(be[v]);
		}
	DFS(be[s], 0);
	ans += M;
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
	}
	scanf("%d", &s);
	cout << solve() << endl;
}
