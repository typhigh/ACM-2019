#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges;
const int MAXN = 300100;
int vis[MAXN];
int n, m;

void addEdge(int u, int v) {
	edges.emplace_back(u, v);
}

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		++kase;
		scanf("%d%d", &n, &m);
		edges.clear();
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v);
		}
		vector<int> ans;
		for (int i = 0; i < m; ++i) {
			int u = edges[i].first;
			int v = edges[i].second;
			if (vis[u] == kase || vis[v] == kase) continue;
			vis[u] = vis[v] = kase;
			ans.push_back(i+1);
		}
		if (ans.size() >= n) {
			puts("Matching");
			for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n - 1]);
			continue;
		}

		ans.clear();
		for (int i = 1; i <= 3 * n; ++i) {
			if (vis[i] == kase) continue;
			ans.push_back(i);
		}
		
		puts("IndSet");
		for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
}
