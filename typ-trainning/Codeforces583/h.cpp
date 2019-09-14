#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
vector<int> G[MAXN];
int n, k, color[MAXN], fa[MAXN], dep[MAXN], ans[MAXN];
bool vis[MAXN];

void AddEdge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

int DFS1(int u) {
	int id = u;
	for (int v: G[u]) {
		if (v == fa[u]) continue;
		dep[v] = dep[u] + 1; 
		fa[v] = u;
		int t = DFS1(v);
		if (dep[t] > dep[id]) id = t;
	}
	return id;
}

int DFS2(int u, int d) {
//	cout << " DFS " << u << " " << dep[u] << endl;
	int s = dep[u];
	for (int v : G[u]) {
		if (v == fa[u] || vis[v]) continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		ans[v] = (ans[u] + d + k) % k;
		s = max(s, DFS2(v, d));
	}
	return s;
}

int num[MAXN];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
	}
	fa[1] = dep[1] = 0;
	int u = DFS1(1);
	dep[u] = fa[u] = 0;
	int v = DFS1(u);
	int cnt = 0;
//	cout << u << " " << v << endl;
	for (int i = v, last = 0; i > 0; last = i, i = fa[i]) {
//		cout << i << endl;
		num[++cnt] = i;
		vis[i] = 1;
		ans[i] = (ans[last] + 1) % k;
	}
	for (int i = 1; i <= cnt; ++i) {
		int x = num[i];
		dep[x] = fa[x] = 0;
		int t = DFS2(x, (i <= (cnt >> 1)) ? -1: 1);
//		printf("[%d] %d\n", i, t);
		if (t && t + min(i, cnt-i+1) >= k && k > 2) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i = 1; i <= n; ++i) printf("%d%c", ans[i]+1, " \n"[i == n]);
	return 0;
}
