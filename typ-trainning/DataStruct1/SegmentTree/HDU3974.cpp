#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, m, lazy[MAXN<<2];

// mapped to tree node 
int L[MAXN], R[MAXN], dfs_clock;
vector<int> G[MAXN];
bool used[MAXN];

void DFS(int u) {
	L[u] = ++dfs_clock;
	for (int v : G[u]) DFS(v);
	R[u] = dfs_clock;
}

void build() {
	lazy[1] = -2;
}

void pushDown(int id) {
	if (~lazy[id]) {
		lazy[id<<1] = lazy[id<<1|1] = lazy[id];
		lazy[id] = -1;
	}
}

void update(int id, int l, int r, int L, int R, int d) {
	if (L <= l && r <= R) {
		lazy[id] = d;
		return;
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	if (L <= mid) update(id<<1, l, mid, L, R, d);
	if (R > mid) update(id<<1|1, mid+1, r, L, R, d);
}

int query(int id, int l, int r, int x) {
	if (~lazy[id]) return lazy[id];
	if (l == r) {
		// impossible reach
		return lazy[id];
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	if (x <= mid) return query(id<<1, l, mid, x);
	else return query(id<<1|1, mid+1, r, x);
}

void init() {
	for (int i = 1; i <= n; ++i) {
		used[i] = false;
		G[i].clear();
	}
	dfs_clock = 0;
}

char s[10];
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d:\n", ++kase);
		scanf("%d", &n);
		init();
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			used[u] = true;
			G[v].push_back(u);
		}
		int root = 0;
		for (int i = 1; i <= n; ++i) 
			if (!used[i]) root = i;
		assert(root);
		DFS(root);
		build();
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			scanf("%s", s);
			int x, y;
			if (s[0] == 'C') {
				scanf("%d", &x);
				int ans = query(1, 1, n, L[x]);
				if (ans == -2) ans = -1;
				printf("%d\n", ans);
			} else if (s[0] == 'T') {
				scanf("%d %d", &x, &y);
				update(1, 1, n, L[x], R[x], y);
			}
		}
	}
}


